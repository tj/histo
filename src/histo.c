
//
// histo.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include "histo.h"

/*
 * Return the maximum absolute value in `data`.
 */

float
max(float data[], int len) {
  float n = data[0];
  for (int i = 1; i < len; ++i) {
    float c = data[i] < 0 ? -data[i] : data[i];
    n = c > n ? c : n;
  }
  return n;
}

/*
 * Draw `len` values of `data`.
 */

void
draw_histogram(float data[], int len) {
  float m = max(data, len);
  int pad = 4;
  int n = 0;

  int w, h;
  term_size(&w, &h);

  // clear
  term_clear("screen");

  // y-axis
  term_move_to(pad, 1);
  while (n < (h - pad - 1)) {
    term_move_by(0, 2);
    term_color("grey");
    printf("․");
    n += 2;
  }

  // x-axis
  n = 0;
  term_move_to(pad, h - 2);
  while (n < (w - pad * 3)) {
    term_color("grey");
    printf("․");
    term_move_by(5, 0);
    n += 5;
  }

  // plot data

  int x = 1;
  for (int i = 0; i < len; ++i) {
    float p = 0 == data[i] ? 0 : data[i] / m;
    int y = (h - pad) * p;
    char *c = y < 0 ? "░" : "█";
    if (y < 0) y = -y;
    while (y--) {
      term_move_to(x * 5 + pad, y - 1 - h + pad);
      term_reset();
      printf("%s", c);
    }
    x++;
  }

  term_move_to(w, h - 1);

  // flush
  printf("\n");
}
