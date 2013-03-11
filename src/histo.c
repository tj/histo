
//
// histo.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <term.h>
#include "histo.h"

/*
 * Return the maximum absolute value in `data`.
 */

int
max(int data[], int len) {
  int n = data[0];
  for (int i = 1; i < len; ++i) {
    int c = data[i] < 0 ? -data[i] : data[i];
    n = c > n ? c : n;
  }
  return n;
}

/*
 * Return the char-length of `n`.
 */

int
width_of(int n) {
  if (0 == n) return 1;
  return (int) (log10(n) + 1);
}

/*
 * Draw `len` values of `data`.
 */

void
draw_histogram(int data[], int len) {
  int m = max(data, len);
  int xbarw = 2;
  int xpad = 4;
  int ypad = 4;
  int n = 0;

  // term size
  int w, h;
  term_size(&w, &h);

  // histogram size
  int xw = width_of(m);
  int hh = h - ypad - 1;
  xpad += xw;

  // clear
  term_clear("screen");

  // y-axis labels
  term_move_to(2, 1);
  while (n < (hh + 1)) {
    term_move_by(0, 2);
    term_color("grey");
    float p = (float) (hh-n) / hh;
    printf("%*.0f", xw, m * p);
    n += 2;
  }

  // y-axis
  n = 0;
  term_move_to(3 + xw, 1);
  while (n < (h - ypad)) {
    term_move_by(0, 2);
    term_color("grey");
    printf("․");
    n += 2;
  }

  // x-axis
  n = 0;
  term_move_to(3 + xpad, h - 2);
  while (n < (w - xpad * 3)) {
    term_color("grey");
    printf("․");
    term_move_by(xbarw, 0);
    n += xbarw;
  }

  // plot data
  int x = 0;
  int sx = xpad + 3;
  int mx = (w - sx) / (xbarw + 1);
  for (int i = 0; i < len; ++i) {
    if (x > mx) break;
    float p = 0 == data[i] ? 0 : (float) data[i] / m;
    int y = (h - ypad) * p;
    char *c = y < 0 ? "░" : "█";
    if (y < 0) y = -y;
    while (y--) {
      term_move_to(sx + x * xbarw, abs(y - 1 - h + ypad));
      term_reset();
      printf("%s", c);
    }
    x++;
  }

  term_move_to(w, h - 1);

  // flush
  printf("\n");
}
