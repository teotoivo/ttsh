#ifndef TTSH_INPUT_H
#define TTSH_INPUT_H
#include <stddef.h>
#include <termios.h>

#define TTSH_INITIAL_LINE_BUFFSIZE 128

void handle_eof(char *c);

int handle_newline(char *c, char **buffer, size_t *pos, size_t *length);

bool handle_backspace(char *c, size_t *pos);

void remove_character(char **array, int index, int array_length);

/**
 * ttsh_read_line - Reads a line of input from stdin and processes
 * continuations.
 *
 * @return A pointer to the processed input line. The caller is responsible for
 * freeing it.
 */
char *ttsh_read_line(void);

bool process_arrow_key(char initial, size_t *pos);

#endif
