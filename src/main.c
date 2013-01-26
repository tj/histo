
//
// main.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <commander.h>

static void
verbose(command_t *self) {
  printf("verbose: enabled\n");
}

static void
required(command_t *self) {
  printf("required: %s\n", self->arg);
}

static void
optional(command_t *self) {
  printf("optional: %s\n", self->arg);
}

int
main(int argc, char **argv){
  command_t cmd;
  command_init(&cmd, argv[0], "0.0.1");
  command_parse(&cmd, argc, argv);
  command_free(&cmd);
  return 0;
}
