#include "ttsh_core.h"
#include "ttsh_builtins.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void ttsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    p(" >");
    line = ttsh_read_line();
    args = ttsh_tokenize(line);
    status = ttsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

char *ttsh_read_line() {
  char *line = NULL;
  size_t buffsize = 0;

  Getline(&line, &buffsize, stdin);

  return line;
}

char **ttsh_tokenize(char *line) {
  int buffsize = TTSH_TOKEN_BUFFSIZE;
  int position = 0;
  char *token;
  char **tokens = Malloc(buffsize * sizeof(char *));

  token = strtok(line, TTSH_TOKEN_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= buffsize) {
      buffsize += TTSH_TOKEN_BUFFSIZE;
      tokens = Realloc(tokens, buffsize * sizeof(char *));
    }

    token = strtok(NULL, TTSH_TOKEN_DELIM);
  }

  tokens[position] = NULL;
  return tokens;
}

int ttsh_launch(char **args) {
  pid_t pid;
  int status;

  pid = Fork();

  if (pid == 0) {
    // Child process
    Execvp(args[0], args); // Executes the command or exits on failure
    exit(EXIT_FAILURE);    // Only reached if Execvp fails. Explicit exit.

  } else {
    // Parent process
    Waitpid(pid, &status, 0); // Wait for child.
  }

  return 1;
}

int ttsh_execute(char **args) {
  if (args[0] == NULL) {
    return 1;
  }

  int num_builtins = ttsh_num_builtins(); // Store the value
  for (int i = 0; i < num_builtins; i++) {
    if (strcmp(args[0], builtins[i].name) == 0) {
      return (*builtins[i].function)(args);
    }
  }

  return ttsh_launch(args);
}
