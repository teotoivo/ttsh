#ifndef UTILS_H
#define UTILS_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color macros
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_WHITE "\033[37m"

// Printing macros
#define PRINT_COLOR(color, msg, ...)                                           \
  do {                                                                         \
    fprintf(stdout, color msg COLOR_RESET "\n", ##__VA_ARGS__);                \
  } while (0)

#define PRINT_ERROR(msg, ...)                                                  \
  do {                                                                         \
    fprintf(stderr, COLOR_RED msg COLOR_RESET "\n", ##__VA_ARGS__);            \
  } while (0)

#define PRINT_WARNING(msg, ...)                                                \
  do {                                                                         \
    fprintf(stderr, COLOR_YELLOW msg COLOR_RESET "\n", ##__VA_ARGS__);         \
  } while (0)

// Safe fopen
#define SAFE_FOPEN(file, path, mode)                                           \
  do {                                                                         \
    file = fopen(path, mode);                                                  \
    if (!file) {                                                               \
      PRINT_ERROR("Failed to open file '%s': %s", path, strerror(errno));      \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)

// Safe malloc
#define SAFE_MALLOC(ptr, size)                                                 \
  do {                                                                         \
    ptr = malloc(size);                                                        \
    if (!ptr) {                                                                \
      PRINT_ERROR("Memory allocation failed: %s", strerror(errno));            \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)

// Safe realloc
#define SAFE_REALLOC(ptr, new_size)                                            \
  do {                                                                         \
    void *temp = realloc(ptr, new_size);                                       \
    if (!temp) {                                                               \
      PRINT_ERROR("Memory reallocation failed: %s", strerror(errno));          \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    ptr = temp;                                                                \
  } while (0)

#endif // UTILS_H
