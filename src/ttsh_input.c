#include "ttsh_input.h"
#include "ttsh_utils.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function declarations
static void refresh_line(const char *buffer, size_t pos, size_t length);
static void insert_character(char *buffer, char c, size_t *pos, size_t *length);
static void delete_character(char *buffer, size_t *pos, size_t *length);
static void process_escape_sequence(size_t *pos, size_t length);

char *ttsh_read_line(void) {
  size_t bufsize = TTSH_INITIAL_LINE_BUF_SIZE;
  size_t pos = 0;
  size_t length = 0;
  char *buffer = Malloc(bufsize);

  while (1) {
    if (length >= bufsize) {
      bufsize += TTSH_INITIAL_LINE_BUF_SIZE;
      buffer = Realloc(buffer, bufsize);
    }

    char c;
    ssize_t nread = Read(STDIN_FILENO, &c, 1);
    (void)nread; // Unused variable

    if (c == CTRL_D) {
      ERROR("[EOF]");
      exit(EXIT_SUCCESS);
    } else if (c == '\n' || c == '\r') {
      Write(STDOUT_FILENO, "\n\r", 2);
      break;
    } else if (c == KEY_BACKSPACE_1 || c == KEY_BACKSPACE_2) {
      if (pos > 0) {
        delete_character(buffer, &pos, &length);
      }
    } else if (c == KEY_ESCAPE) {
      process_escape_sequence(&pos, length);
    } else if (c == '\t') {
      // Skip tab characters
    } else {
      insert_character(buffer, c, &pos, &length);
    }
  }

  // Null-terminate the string.
  buffer[length] = '\0';
  return buffer;
}

// Refresh the display after modifications.
static void refresh_line(const char *buffer, size_t pos, size_t length) {
  // Write out the characters from the current position.
  Write(STDOUT_FILENO, &buffer[pos], length - pos);
  // Clear the extra character at the end.
  Write(STDOUT_FILENO, " ", 1);
  // Move the cursor back to the proper position.
  for (size_t i = pos; i < length + 1; i++) {
    Write(STDOUT_FILENO, "\b", 1);
  }
}

// Insert a character at the current position.
static void insert_character(char *buffer, char c, size_t *pos,
                             size_t *length) {
  // If inserting in the middle, shift the rest of the characters.
  if (*pos < *length) {
    memmove(&buffer[*pos + 1], &buffer[*pos], *length - *pos);
    buffer[*pos] = c;
    (*length)++;
    // Write the inserted character and the rest of the line.
    Write(STDOUT_FILENO, &buffer[*pos], *length - *pos);
    // Move the cursor back to the correct position.
    for (size_t i = 0; i < *length - *pos - 1; i++) {
      Write(STDOUT_FILENO, "\b", 1);
    }
    (*pos)++;
  } else {
    // Append at the end.
    buffer[*pos] = c;
    Write(STDOUT_FILENO, &c, 1);
    (*pos)++;
    (*length)++;
  }
}

// Delete the character immediately before the current position.
static void delete_character(char *buffer, size_t *pos, size_t *length) {
  (*pos)--;
  // Shift the rest of the characters left.
  for (size_t i = *pos; i < *length; i++) {
    buffer[i] = buffer[i + 1];
  }
  (*length)--;
  // Move cursor back, refresh the rest of the line, and clear the extra
  // character.
  Write(STDOUT_FILENO, "\b", 1);
  refresh_line(buffer, *pos, *length);
}

// Process escape sequences for cursor movements.
static void process_escape_sequence(size_t *pos, size_t length) {
  char seq[2];
  // Read the next two bytes to determine the escape sequence.
  if (Read(STDIN_FILENO, &seq[0], 1) == 0)
    return;
  if (Read(STDIN_FILENO, &seq[1], 1) == 0)
    return;

  if (seq[0] == '[') {
    switch (seq[1]) {
    case 'D': // Left arrow
      if (*pos > 0) {
        (*pos)--;
        Write(STDOUT_FILENO, "\x1b[D", 3);
      }
      break;
    case 'C': // Right arrow
      if (*pos < length) {
        (*pos)++;
        Write(STDOUT_FILENO, "\x1b[C", 3);
      }
      break;
    case 'A': // Up arrow (history navigation placeholder)
      // TODO: Implement history navigation for arrow up.
      break;
    case 'B': // Down arrow (history navigation placeholder)
      // TODO: Implement history navigation for arrow down.
      break;
    default:
      // Unhandled escape sequence.
      break;
    }
  }
}
