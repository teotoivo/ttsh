#include "ttsh_tokenizer.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char **ttsh_tokenize(char *line) {
  size_t buffsize = TTSH_TOKEN_BUFFSIZE;
  char **tokens = malloc(buffsize * sizeof(char *));
  size_t position = 0;
  char *start = line;
  char last_char = '\0';
  char quote_char = '\0';
  bool in_expansion = false;
  int expansion_nesting_counter = 0;
  char *expansion_start = NULL;

  while (*line != '\0') {
    if (last_char == '$' && *line == '(') {
      if (in_expansion) {
        expansion_nesting_counter++;
      } else {
        in_expansion = true;
        expansion_start = line - 1; // Include '$'
      }
    }

    if (in_expansion) {
      if (*line == ')') {
        if (expansion_nesting_counter == 0) {
          in_expansion = false;
          tokens[position++] =
              strndup(expansion_start, line - expansion_start + 1);
          start = line + 1;
        } else {
          expansion_nesting_counter--;
        }
      }
    } else {
      if (*line == '"' || *line == '\'') {
        if (quote_char == '\0') {
          quote_char = *line;
          start = line + 1;
        } else if (*line == quote_char) {
          *line = '\0';
          tokens[position++] = strdup(start);
          quote_char = '\0';
          start = line + 1;
        }
      } else if (quote_char == '\0' && strchr(TTSH_TOKEN_DELIM, *line)) {
        *line = '\0';
        if (line > start) {
          tokens[position++] = strdup(start);
        }
        start = line + 1;
      }
    }

    if (position >= buffsize) {
      buffsize += TTSH_TOKEN_BUFFSIZE;
      tokens = realloc(tokens, buffsize * sizeof(char *));
    }

    last_char = *line;
    line++;
  }

  if (line > start) {
    tokens[position++] = strdup(start);
  }
  tokens[position] = NULL;
  return tokens;
}
