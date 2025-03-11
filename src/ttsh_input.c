#include "ttsh_input.h"
#include "ttsh_prompt.h"
#include "ttsh_utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_LINES 100

char *ttsh_read_line(void) {
  size_t bufsize = TTSH_INITIAL_LINE_BUFFSIZE;
  size_t pos = 0;
  size_t length = 0;
  char *buffer = Malloc(bufsize);
  char line_starts[MAX_LINES] = {0};

  while (1) {
    if (length >= bufsize) {
      bufsize += TTSH_INITIAL_LINE_BUFFSIZE;
      buffer = Realloc(buffer, bufsize);
    }
    char c;

    ssize_t nread = Read(STDIN_FILENO, &c, 1);
    (void)nread;

    handle_eof(&c);

    // handles new line
    if (c == '\r' || c == '\n') {
      if (buffer[pos - 1] == '\\') { // should continue command writing
        Write(STDOUT_FILENO, "\r\n", 2);
        buffer[pos++] = '\n';
        length++;
        continue;
      }
      Write(STDOUT_FILENO, "\r\n", 2);
      break;
    }

    // handles backspace
    if (c == 127 || c == '\b') {
      if (pos > 0) {
        remove_character(&buffer, pos, length);
        length--;
        pos--;
        // Erase the last character from the terminal display
        write(STDOUT_FILENO, "\b \b", 3);
      }
      continue;
    }

    Write(STDIN_FILENO, &c, 1);
    buffer[pos++] = c;
    length++;
  }

  // Null terminate the string
  buffer[pos] = '\0';
  return buffer;
}

bool process_arrow_key(char initial, size_t *pos) {
  if (initial == '\x1b') {
    char seq[2];
    if (Read(STDIN_FILENO, &seq[0], 1) != 1)
      return true;
    if (Read(STDIN_FILENO, &seq[1], 1) != 1)
      return true;
    if (seq[0] == '[') {
      switch (seq[1]) {
      case 'D': // Left arrow
        break;
      case 'C': // Right arrow
        // Implement if needed
        break;
      case 'A': // Up arrow
        // History handling could be implemented here.
        break;
      case 'B': // Down arrow
        // History handling could be implemented here.
        break;
      default:
        break;
      }
    }
    return true;
  }
  return false;
}

void handle_eof(char *c) {
  if (*c == 0x04) {
    ERROR("[EOF]");
    exit(EXIT_SUCCESS);
  }
}

void remove_character(char **array, int index, int array_length) {
  int i;
  for (i = index; i < array_length - 1; i++)
    array[i] = array[i + 1];
}
