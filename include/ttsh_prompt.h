#ifndef TTSH_PROMPT_H
#define TTSH_PROMPT_H
#include <stddef.h>

extern size_t current_prompt_length;

void print_prompt(void);
char *get_short_cwd(void);

#endif // !TTSH_PROMPT_H
