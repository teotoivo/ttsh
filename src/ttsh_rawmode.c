#include "ttsh_rawmode.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void enableRawMode() {
  // Get the current terminal attributes.
  if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
    perror("tcgetattr");
    exit(EXIT_FAILURE);
  }

  // Ensure raw mode is disabled on program exit.
  atexit(disableRawMode);

  struct termios raw = orig_termios;

  // Disable echoing, canonical mode, extended functions, and signal characters.
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

  // Disable special handling of input bytes.
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

  // Disable output processing.
  raw.c_oflag &= ~(OPOST);

  // Set character size to 8 bits per byte.
  raw.c_cflag |= (CS8);

  raw.c_cc[VMIN] = 1;
  raw.c_cc[VTIME] = 0;

  // Apply the new terminal attributes.
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
    perror("tcsetattr");
    exit(EXIT_FAILURE);
  }
}

void disableRawMode() {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) {
    perror("tcsetattr");
    exit(EXIT_FAILURE);
  }
}
