#include "ttsh_input.h"
#include "linenoise.h"

char *ttsh_readline(char *prompt) {
  linenoiseSetMultiLine(1);

  char *line = linenoise(prompt);

  return line;
}
