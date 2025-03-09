#include "ttsh_utils.h"
#include "ttsh_config.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern Config *config; // Ensure that global config is defined elsewhere
// Assume COLOR_RESET is defined elsewhere, for example:
// #define COLOR_RESET "\033[0m"

/* Malloc wrapper using error color from config */
void *Malloc(size_t size) {
  void *ptr;

  if (size == 0)
    return NULL;
  ptr = malloc(size);
  if (!ptr) {
    PERROR("Malloc failed");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

/* Realloc wrapper using error color from config */
void *Realloc(void *ptr, size_t size) {
  void *new_ptr;

  new_ptr = realloc(ptr, size);
  if (!new_ptr && size != 0) {
    PERROR("Realloc failed");
    exit(EXIT_FAILURE);
  }
  return new_ptr;
}

/* Getline wrapper using error color from config */
void Getline(char **lineptr, size_t *n, FILE *stream) {
  if (!lineptr || !stream) {
    ERROR("Getline: invalid arguments\n");
    return;
  }
  if (getline(lineptr, n, stream) == -1) {
    free(*lineptr);
    *lineptr = NULL;
    if (feof(stream)) {
      printf("%s[EOF]%s\n", config->theme.error, COLOR_RESET);
      exit(EXIT_SUCCESS);
    } else {
      PERROR("Getline failed");
      exit(EXIT_FAILURE);
    }
  }
}

/* Change directory with error message using config error color */
void Chdir(const char *path) {
  if (!path) {
    fprintf(stderr, "%scd: path argument required%s\n", config->theme.error,
            COLOR_RESET);
    ERROR("cd: path argument required\n");
    return;
  }
  if (chdir(path) == -1)
    PERROR("cd failed");
}

/* Fork wrapper using error color from config */
pid_t Fork(void) {
  pid_t pid;

  pid = fork();
  if (pid < 0) {
    PERROR("fork failed");
    exit(EXIT_FAILURE);
  }
  return pid;
}

/* Execvp wrapper using error color from config */
void Execvp(const char *file, char *const argv[]) {
  if (!file || !argv) {
    fprintf(stderr, "%sExecvp: invalid arguments%s\n", config->theme.error,
            COLOR_RESET);
    exit(EXIT_FAILURE);
  }
  if (execvp(file, argv) == -1) {
    PERROR("ttsh failed");
    exit(EXIT_FAILURE);
  }
}

/* Wait wrapper using error color from config */
pid_t Wait(int *status) {
  pid_t result;

  if (!status) {
    ERROR("Wait: status argument required\n");
    return -1;
  }
  result = wait(status);
  if (result == -1)
    PERROR("wait failed");
  if (WIFEXITED(*status))
    *status = WEXITSTATUS(*status);
  return result;
}

/* Waitpid wrapper using error color from config */
pid_t Waitpid(pid_t pid, int *status, int options) {
  pid_t result;

  if (!status)
    return -1;
  result = waitpid(pid, status, options);
  if (result == -1)
    PERROR("waitpid failed");
  if (WIFEXITED(*status))
    *status = WEXITSTATUS(*status);
  return result;
}

/* Check if a string ends with a given suffix */
bool endsWith(const char *str, const char *suffix) {
  if (!str || !suffix) {
    return false;
  }
  size_t str_len = strlen(str);
  size_t suffix_len = strlen(suffix);

  if (suffix_len > str_len) {
    return false;
  }
  return (strcmp(str + str_len - suffix_len, suffix) == 0);
}
