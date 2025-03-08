#include "ttsh_builtins.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

builtin_command builtins[] = {
    {"cd", ttsh_cd}, {"help", ttsh_help}, {"exit", ttsh_exit}, {NULL, NULL}};

int ttsh_num_builtins() {
  int i = 0;
  while (builtins[i].name != NULL) {
    i++;
  }
  return i;
}

int ttsh_cd(char **args) {
  if (args[1] == NULL) {
    ERROR("ttsh: expected arguments to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror(COLOR_RED "lsh" COLOR_RESET);
    }
  }
  return 1;
}

int ttsh_help(char **args) {
  (void)args;
  p("TeoToivoShell\n\n");
  p("Following commands are builtin:\n");

  for (int i = 0; i < ttsh_num_builtins(); i++) {
    p("  %s\n", builtins[i].name);
  }
  return 1;
}

int ttsh_exit(char **args) {
  (void)args;
  return 0;
}
