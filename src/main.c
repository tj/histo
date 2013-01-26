
//
// main.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <commander.h>
#include <term.h>
#include "histo.h"

/*
 * Reset on SIGINT.
 */

void
on_sigint(int sig) {
  term_clear("screen");
  term_show_cursor();
  exit(1);
}

/*
 * Histogram.
 */

int
main(int argc, char **argv){
  command_t cmd;
  command_init(&cmd, argv[0], "0.0.1");
  command_parse(&cmd, argc, argv);

  // term width for rotation
  int w, h;
  term_size(&w, &h);

  // values
  float vals[256];
  int n = 0;

  // term_hide_cursor();
  signal(SIGINT, on_sigint);

  for (;;) {
    float val;
    int ret = fscanf(stdin, "%f", &val);

    // EOF
    if (feof(stdin)) exit(0);

    // parse error
    if (ret < 1) {
      fprintf(stderr, "invalid input syntax\n");
      exit(1);
    }

    // draw
    vals[n++ % w] = val;
    draw_histogram(vals, n > w ? w : n);
  }

  term_show_cursor();
  command_free(&cmd);
  return 0;
}
