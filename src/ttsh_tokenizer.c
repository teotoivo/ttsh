#include "ttsh_tokenizer.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void append_token(char ***tokens, size_t *position, size_t *buffsize,
                         const char *start, size_t len) {
  if (*position >= *buffsize) {
    *buffsize += TTSH_TOKEN_BUFFSIZE;
    *tokens = realloc(*tokens, *buffsize * sizeof(char *));
  }
  (*tokens)[(*position)++] = strndup(start, len);
}

static bool is_delimiter(char c) {
  return (strchr(TTSH_TOKEN_DELIM, c) != NULL);
}

char **ttsh_tokenize(char *line) {
  size_t buffsize = TTSH_TOKEN_BUFFSIZE;
  char **tokens = malloc(buffsize * sizeof(char *));
  size_t position = 0;
  char *start = line;
  char last_char = '\0';
  char quote_char = '\0';
  bool in_expansion = false;
  int expansion_nesting = 0;
  char *expansion_start = NULL;

  while (*line != '\0') {
    // Detect start of expansion "$("
    if (!in_expansion && last_char == '$' && *line == '(') {
      in_expansion = true;
      expansion_start = line - 1; // include '$'
    }

    if (in_expansion) {
      // Handle nested expansion and end of expansion
      if (*line == '(') {
        expansion_nesting++;
      } else if (*line == ')') {
        if (expansion_nesting == 0) {
          in_expansion = false;
          append_token(&tokens, &position, &buffsize, expansion_start,
                       line - expansion_start + 1);
          start = line + 1;
        } else {
          expansion_nesting--;
        }
      }
    } else {
      // Handle quoted tokens.
      if (*line == '"' || *line == '\'') {
        if (quote_char == '\0') {
          // Starting a quoted section.
          quote_char = *line;
          start = line + 1;
        } else if (*line == quote_char) {
          // End of a quoted section.
          *line = '\0';
          append_token(&tokens, &position, &buffsize, start, line - start);
          quote_char = '\0';
          start = line + 1;
        }
      } else if (quote_char == '\0' && is_delimiter(*line)) {
        // Handle token boundaries based on delimiters.
        *line = '\0';
        if (line > start) {
          append_token(&tokens, &position, &buffsize, start, line - start);
        }
        start = line + 1;
      }
    }

    last_char = *line;
    line++;
  }

  // Capture any trailing token.
  if (line > start) {
    append_token(&tokens, &position, &buffsize, start, line - start);
  }
  tokens[position] = NULL;
  return tokens;
}
