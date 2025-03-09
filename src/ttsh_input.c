#include "ttsh_input.h"
#include "ttsh_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ttsh_read_line(void) {
  char *line = NULL;
  size_t buffsize = 0;

  Getline(&line, &buffsize, stdin);

  size_t len = strlen(line);
  if (len > 0 && line[len - 1] == '\n') {
    line[len - 1] = '\0';
  }

  line = handle_line_continuation(line);
  line = handle_logical_operator_line_continuation(line);

  return line;
}

char *handle_line_continuation(char *line) {
  while (endsWith(line, "\\")) {
    char *temp_line = NULL;
    size_t temp_buffsize = 0;
    printf(">");

    /* Remove the trailing backslash */
    line[strlen(line) - 1] = '\0';

    Getline(&temp_line, &temp_buffsize, stdin);

    size_t temp_len = strlen(temp_line);
    if (temp_len > 0 && temp_line[temp_len - 1] == '\n') {
      temp_line[temp_len - 1] = '\0';
    }

    size_t new_size = strlen(line) + strlen(temp_line) + 1;
    line = Realloc(line, new_size);
    strcat(line, temp_line);

    free(temp_line);
  }
  return line;
}

char *handle_logical_operator_line_continuation(char *line) {
  while (endsWith(line, "||") || endsWith(line, "&&")) {
    char *temp_line = NULL;
    size_t temp_buffsize = 0;
    printf(">");

    Getline(&temp_line, &temp_buffsize, stdin);

    size_t temp_len = strlen(temp_line);
    if (temp_len > 0 && temp_line[temp_len - 1] == '\n') {
      temp_line[temp_len - 1] = '\0';
    }

    /* Ensure a space exists between tokens if needed */
    if (!endsWith(line, "|| ") && !endsWith(line, "&& ")) {
      size_t new_size = strlen(line) + 2; /* 1 for space, 1 for null */
      line = Realloc(line, new_size);
      strcat(line, " ");
    }

    size_t new_size = strlen(line) + strlen(temp_line) + 2;
    line = Realloc(line, new_size);
    strcat(line, temp_line);

    free(temp_line);
  }
  return line;
}
