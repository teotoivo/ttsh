#include "ttsh_prompt.h"
#include "ttsh_config.h"
#include "ttsh_utils.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

size_t current_prompt_length;

void print_prompt(void) {
  char *cwd = get_short_cwd();
  char *prefix = get_config()->options.prompt_prefix;

  // Calculate the visible length of the prompt.
  // The first part is the cwd and the second part is the prompt prefix
  // surrounded by spaces.
  current_prompt_length =
      strlen(cwd) + strlen(prefix) + 2; // +2 for the two spaces

  // Print the prompt parts with the specified color themes.
  pc(get_config()->theme.cdir, "%s", cwd);
  pc(get_config()->theme.prompt_prefix, " %s ", prefix);
}

char *get_short_cwd(void) {
  // Get current working directory; getcwd() allocates enough memory.
  char *cwd = getcwd(NULL, 0);
  if (!cwd) {
    perror("getcwd");
    return NULL;
  }

  size_t len = strlen(cwd);
  char *short_cwd = NULL;

  // If the cwd is short enough, just duplicate it.
  if (len <= 25) {
    short_cwd = strdup(cwd);
  } else {
    // Allocate 26 bytes: 25 characters + 1 for the null terminator.
    short_cwd = malloc(26);
    if (!short_cwd) {
      perror("malloc");
      free(cwd);
      return NULL;
    }
    // Use an ellipsis followed by the last 22 characters of the cwd.
    strcpy(short_cwd, "...");
    strncpy(short_cwd + 3, cwd + (len - 22), 22);
    short_cwd[25] = '\0';
  }

  free(cwd);
  return short_cwd;
}
