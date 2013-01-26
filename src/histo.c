
//
// histo.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include "histo.h"

void
draw_histogram(float data[]) {
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
    term_move_by(6, 0);
    n += 6;
  }

  // plot data

  int x = 0;
  for (int i = 0; -1 != data[i]; ++i) {
    float y = data[i];
    while (y--) {
      term_move_to(x * 6 + pad, y - h + pad);
      term_reset();
      printf("█");
    }
    x++;
  }

  term_move_to(w, h - 1);

  // flush
  printf("\n");
}
