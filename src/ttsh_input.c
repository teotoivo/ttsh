#include "ttsh_input.h"
#include "linenoise.h"
#include "ttsh_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool should_readline_continue(char *line);

char *ttsh_readline(char *prompt) {
  linenoiseSetMultiLine(1);

  char *line = linenoise(prompt);
  if (line == NULL) {
    ERROR("[EOF]");
    exit(EXIT_SUCCESS);
  }

  while (should_readline_continue(line)) {
    char *new_line = linenoise(" > ");
    if (new_line == NULL) {
      ERROR("[EOF]");
      exit(EXIT_SUCCESS);
    }

    Realloc(line, strlen(line) + strlen(new_line) + 1);

    strcat(line, new_line);

    free(new_line);
  }

  printf("%s", line);
  return line;
}

bool should_readline_continue(char *line) {
  int line_len = strlen(line);
  if (line[line_len - 1] == '\\') {
    line[line_len - 1] = '\0';

    return true;
  }

  if ((line[line_len - 1] == '&' && line[line_len - 2] == '&') ||
      (line[line_len - 1] == '|' && line[line_len - 2] == '|')) {
    Realloc(line, ++line_len);

    line[line_len - 1] = ' ';
    line[line_len] = '\0';
    return true;
  }

  return false;
}
