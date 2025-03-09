#ifndef TTSH_CONFIG_H
#define TTSH_CONFIG_H

#define TTSH_MAX_CONFIG_STRING_LEGTH 1024

#define DEFAULT_PROMPT_PREFIX ">"

// Define default colors using ANSI escape codes
#define COLOR_DEFAULT_PROMPT_PREFIX "\033[1;34m" // Bright blue
#define COLOR_DEFAULT_CDIR "\033[1;32m"          // Bright yellow
#define COLOR_DEFAULT_ERROR "\033[1;31m"         // Bright red
#define COLOR_RESET "\033[0m"

/**
 * struct Theme - Contains color settings for various shell elements.
 * @prompt: Color used for the main shell prompt.
 * @prompt_prefix: Color used for the prompt prefix (e.g., username or
 * symbol).
 * @cdir: Color for the current directory display.
 * @error: Color used for error messages.
 */
typedef struct {
  char prompt[TTSH_MAX_CONFIG_STRING_LEGTH];
  char prompt_prefix[TTSH_MAX_CONFIG_STRING_LEGTH];
  char cdir[TTSH_MAX_CONFIG_STRING_LEGTH];
  char error[TTSH_MAX_CONFIG_STRING_LEGTH];
} Theme;

/**
 * struct Options - Contains options for the shell
 * @prompt_prefix:  The prefix for the prompt
 */
typedef struct {
  char prompt_prefix[TTSH_MAX_CONFIG_STRING_LEGTH];
} Options;

/**
 * struct Config - Global configuration for the shell.
 * @theme: A Theme struct containing color settings.
 * @options: Options for the prompt
 */
typedef struct {
  Theme theme;
  Options options;
} Config;

extern Config *config;

void load_config();
void load_default_config(Config **config);

Config *get_config(void);

#endif // !TTSH_CONFIG_H
