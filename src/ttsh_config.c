#include "ttsh_config.h"
#include "ttsh_utils.h"
#include <string.h>

Config *config = NULL;

void load_config() {
  config = Malloc(sizeof(Config));

  load_default_config(&config);
}

void load_default_config(Config **config) {
  // Set default theme colors
  strncpy(get_config()->theme.prompt_prefix, COLOR_DEFAULT_PROMPT_PREFIX,
          TTSH_MAX_CONFIG_STRING_LEGTH);
  strncpy(get_config()->theme.cdir, COLOR_DEFAULT_CDIR,
          TTSH_MAX_CONFIG_STRING_LEGTH);
  strncpy(get_config()->theme.error, COLOR_DEFAULT_ERROR,
          TTSH_MAX_CONFIG_STRING_LEGTH);
  strncpy(get_config()->theme.prompt_prefix, COLOR_DEFAULT_PROMPT_PREFIX,
          TTSH_MAX_CONFIG_STRING_LEGTH);

  // Set default options values (if any)
  // For example, setting prompt_prefix in options to the same as theme's
  // prompt_prefix
  strncpy((*config)->options.prompt_prefix, DEFAULT_PROMPT_PREFIX,
          TTSH_MAX_CONFIG_STRING_LEGTH);
}

Config *get_config(void) {
  if (config == NULL) {
    ERROR("Fatal error: Configuration not initialized (file %s, line %d).\n",
          __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  return config;
}
