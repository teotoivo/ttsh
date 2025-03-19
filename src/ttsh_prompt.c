#include "ttsh_prompt.h"
#include "ttsh_config.h"
#include "ttsh_utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t current_prompt_length;

char *get_short_cwd(void) {
  char *cwd = getcwd(NULL, 0);
  if (!cwd) {
    perror("getcwd");
    return NULL;
  }
  size_t len = strlen(cwd);
  char *short_cwd = NULL;

  if (len <= 25) {
    short_cwd = strdup(cwd);
  } else {
    short_cwd = malloc(26); // 25 characters + 1 for null terminator
    if (!short_cwd) {
      perror("malloc");
      free(cwd);
      return NULL;
    }
    strcpy(short_cwd, "...");
    strncpy(short_cwd + 3, cwd + (len - 22), 22);
    short_cwd[25] = '\0';
  }
  free(cwd);
  return short_cwd;
}

/*
 * ttsh_get_prompt builds a string that contains the colored prompt.
 * The final string has the format:
 *   <cdir_color><cwd><reset><prompt_prefix_color> <prefix> <reset>
 *
 * The visible length (excluding color escape codes) is stored in
 * the global current_prompt_length.
 */
char *ttsh_get_prompt(void) {
  char *cwd = get_short_cwd();
  if (!cwd) {
    return NULL;
  }
  char *prefix = get_config()->options.prompt_prefix;

  // Calculate visible length: cwd + prefix + 2 spaces.
  current_prompt_length = strlen(cwd) + strlen(prefix) + 2;

  // Get color codes from the configuration.
  const char *cdir_color = get_config()->theme.cdir;
  const char *prompt_prefix_color = get_config()->theme.prompt_prefix;
  const char *reset_color = COLOR_RESET; // ANSI reset

  // The final string will be:
  // <cdir_color> + cwd + <reset_color> +
  // <prompt_prefix_color> + " " + prefix + " " + <reset_color> + "\0"
  size_t size = strlen(cdir_color) + strlen(cwd) + strlen(reset_color) +
                strlen(prompt_prefix_color) + 1 + strlen(prefix) + 1 +
                strlen(reset_color) + 1; // +1 for the null terminator

  char *prompt_str = malloc(size);
  if (!prompt_str) {
    perror("malloc");
    free(cwd);
    return NULL;
  }

  snprintf(prompt_str, size, "%s%s%s%s %s %s", cdir_color, cwd, reset_color,
           prompt_prefix_color, prefix, reset_color);

  free(cwd);
  return prompt_str;
}
