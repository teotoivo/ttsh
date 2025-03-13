#ifndef TTSH_INPUT_H
#define TTSH_INPUT_H
#include <stddef.h>
#include <termios.h>

#define TTSH_INITIAL_LINE_BUF_SIZE 64

// ASCII Control Characters
#define CTRL_C 3  // Interrupt signal
#define CTRL_D 4  // End-of-file (EOF)
#define CTRL_Z 26 // Suspend process
#define CTRL_L 12 // Clear screen

// Escape key
#define KEY_ESCAPE 27 // ESC

#define KEY_BACKSPACE_1 127
#define KEY_BACKSPACE_2 8

// Additional keys (these sequences can vary between terminal emulators)
#define HOME_KEY_SEQ "\x1b[H" // or "\x1b[1~"
#define END_KEY_SEQ "\x1b[F"  // or "\x1b[4~"
#define PAGE_UP_SEQ "\x1b[5~"
#define PAGE_DOWN_SEQ "\x1b[6~"
#define DELETE_KEY_SEQ "\x1b[3~"

/**
 * ttsh_read_line - Reads a line of input from stdin and processes
 * continuations.
 *
 * @return A pointer to the processed input line. The caller is responsible for
 * freeing it.
 */
char *ttsh_read_line(void);

#endif
