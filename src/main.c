
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

void
on_sigint(int sig) {
  term_clear("screen");
  term_show_cursor();
  exit(1);
}

int
main(int argc, char **argv){
  command_t cmd;
  command_init(&cmd, argv[0], "0.0.1");
  command_parse(&cmd, argc, argv);

  term_hide_cursor();
  signal(SIGINT, on_sigint);

start:
  {
    float data[] = { 0, 2, 3, 5, 3, 7, 3, 8, 10, 12, 4, 2, 4, 3, -1 };
    draw_histogram(data);
    sleep(1);
  }

  {
    float data[] = { 0, 2, 3, 1, 3, 3, 3, 8, 2, 12, 4, 2, 4, 3, -1 };
    draw_histogram(data);
    sleep(1);
  }

  {
    float data[] = { 0, 0, 1, 2, 3, 7, 3, 8, 2, 12, 2, 2, 1, 3, -1 };
    draw_histogram(data);
    sleep(1);
    goto start;
  }

  command_free(&cmd);
  return 0;
}
