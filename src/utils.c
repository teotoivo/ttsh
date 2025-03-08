#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void *Malloc(size_t size) {
  void *ptr;

  if (size == 0)
    return (NULL);
  ptr = malloc(size);
  if (!ptr) {
    perror(COLOR_RED "Malloc failed" COLOR_RESET);
    exit(EXIT_FAILURE);
  }
  return (ptr);
}

void *Realloc(void *ptr, size_t size) {
  void *new_ptr;

  new_ptr = realloc(ptr, size);
  if (!new_ptr && size != 0) {
    perror(COLOR_RED "Realloc failed" COLOR_RESET);
    exit(EXIT_FAILURE);
  }
  return (new_ptr);
}

void Getline(char **lineptr, size_t *n, FILE *stream) {
  if (!lineptr || !stream) {
    fprintf(stderr, COLOR_RED "Getline: invalid arguments\n" COLOR_RESET);
    return;
  }
  if (getline(lineptr, n, stream) == -1) {
    free(*lineptr);
    *lineptr = NULL;
    if (feof(stream)) {
      printf(COLOR_RED "[EOF]" COLOR_RESET "\n");
      exit(EXIT_SUCCESS);
    } else {
      perror(COLOR_RED "Getline failed" COLOR_RESET);
      exit(EXIT_FAILURE);
    }
  }
}

void Chdir(const char *path) {
  if (!path) {
    fprintf(stderr, COLOR_RED "cd: path argument required\n" COLOR_RESET);
    return;
  }
  if (chdir(path) == -1)
    perror(COLOR_RED "cd failed" COLOR_RESET);
}

pid_t Fork(void) {
  pid_t pid;

  pid = fork();
  if (pid < 0) {
    perror(COLOR_RED "Fork failed" COLOR_RESET);
    exit(EXIT_FAILURE);
  }
  return (pid);
}

void Execvp(const char *file, char *const argv[]) {
  if (!file || !argv) {
    fprintf(stderr, COLOR_RED "Execvp: invalid arguments\n" COLOR_RESET);
    exit(EXIT_FAILURE);
  }
  if (execvp(file, argv) == -1) {
    perror(COLOR_RED "ttsh failed" COLOR_RESET);
    exit(EXIT_FAILURE);
  }
}

pid_t Wait(int *status) {
  pid_t result;

  if (!status) {
    fprintf(stderr, COLOR_RED "Wait: status argument required\n" COLOR_RESET);
    return (-1);
  }
  result = wait(status);
  if (result == -1)
    perror(COLOR_RED "Wait failed" COLOR_RESET);
  if (WIFEXITED(*status))
    *status = WEXITSTATUS(*status);
  return (result);
}

pid_t Waitpid(pid_t pid, int *status, int options) {
  pid_t result;

  if (!status)
    return (-1);
  result = waitpid(pid, status, options);
  if (result == -1)
    perror(COLOR_RED "Waitpid failed" COLOR_RESET);
  if (WIFEXITED(*status))
    *status = WEXITSTATUS(*status);
  return (result);
}
