#include "ttsh_execution.h"
#include "ttsh_builtins.h"
#include "ttsh_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int ttsh_launch(char **args) {
  pid_t pid;
  int status;

  pid = Fork();
  if (pid == 0) {
    /* Child process: execute command */
    Execvp(args[0], args);
    exit(EXIT_FAILURE);
  } else {
    /* Parent process: wait for child */
    Waitpid(pid, &status, 0);
    return status;
  }
}

int ttsh_execute(char **args) {
  if (args[0] == NULL)
    return 1;

  int num_builtins = ttsh_num_builtins();
  for (int i = 0; i < num_builtins; i++) {
    if (strcmp(args[0], builtins[i].name) == 0) {
      return (*builtins[i].function)(args);
    }
  }
  return ttsh_launch(args);
}

int count_args(char **tokens) {
  int count = 0;
  while (tokens[count] != NULL) {
    count++;
  }
  return count;
}

int ttsh_process_and_execute(char **args) {
  int arg_count = count_args(args);
  if (arg_count == 0)
    return 0;

  char *current_command[256];
  int cmd_index = 0;
  int last_exit_status = 0;
  bool should_execute = true;

  for (int i = 0; i <= arg_count; i++) {
    if (i == arg_count || (args[i] != NULL && (strcmp(args[i], "&&") == 0 ||
                                               strcmp(args[i], "||") == 0 ||
                                               strcmp(args[i], ";") == 0))) {

      current_command[cmd_index] = NULL;

      if (should_execute && cmd_index > 0) {
        last_exit_status = ttsh_execute(current_command);
      }

      cmd_index = 0;
      if (i < arg_count) {
        if (strcmp(args[i], "&&") == 0) {
          should_execute = (last_exit_status == 0);
        } else if (strcmp(args[i], "||") == 0) {
          should_execute = (last_exit_status != 0);
        } else if (strcmp(args[i], ";") == 0) {
          should_execute = true;
        }
      }
    } else if (args[i] != NULL) {
      current_command[cmd_index++] = args[i];
    }
  }
  return last_exit_status;
}
