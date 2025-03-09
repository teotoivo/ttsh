#ifndef UTILS_H
#define UTILS_H

#include "ttsh_config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define p(...) printf(__VA_ARGS__)

#define pc(color, fmt, ...)                                                    \
  do {                                                                         \
    printf("%s" fmt "%s", color, ##__VA_ARGS__, COLOR_RESET);                  \
  } while (0)

#define ERROR(fmt, ...)                                                        \
  do {                                                                         \
    fprintf(stderr, "%s" fmt "%s\n", get_config()->theme.error, ##__VA_ARGS__, \
            COLOR_RESET);                                                      \
  } while (0)

#define PERROR(fmt, ...)                                                       \
  do {                                                                         \
    char _err_buf[1024];                                                       \
    snprintf(_err_buf, sizeof(_err_buf), "%s" fmt "%s",                        \
             get_config()->theme.error, ##__VA_ARGS__, COLOR_RESET);           \
    perror(_err_buf);                                                          \
  } while (0)

/**
 * Malloc - Allocates memory with error handling
 * @size: Number of bytes to allocate
 * Return: Pointer to allocated memory
 * Corner cases:
 * - Zero size: returns NULL
 * - Allocation failure: prints error and exits
 */
void *Malloc(size_t size);

/**
 * Realloc - Reallocates memory with error handling
 * @ptr: Pointer to previously allocated memory
 * @size: New size in bytes
 * Return: Pointer to reallocated memory
 * Corner cases:
 * - NULL ptr: acts as malloc
 * - Zero size: acts as free
 * - Allocation failure: prints error and exits
 */
void *Realloc(void *ptr, size_t size);

/**
 * Getline - Reads a line from stream with error handling
 * @lineptr: Pointer to buffer containing the line
 * @n: Pointer to size of buffer
 * @stream: Input stream to read from
 * Corner cases:
 * - NULL arguments: prints error
 * - EOF reached: prints EOF message
 * - Read error: prints error message
 */
void Getline(char **lineptr, size_t *n, FILE *stream);

/**
 * Chdir - Changes current working directory with error handling
 * @path: Directory path to change to
 * Corner cases:
 * - NULL path: prints error
 * - Non-existent path: prints error
 * - Permission denied: prints error
 */
void Chdir(const char *path);

/**
 * Fork - Creates a new process with error handling
 * Return: PID of child on success, -1 on failure
 * Corner cases:
 * - System resource limits: prints error and exits
 * - Process table full: prints error and exits
 */
pid_t Fork(void);

/**
 * Execvp - Executes a program with error handling
 * @file: Name of the program to execute
 * @argv: Array of arguments
 * Corner cases:
 * - NULL file/argv: prints error and exits
 * - Command not found: prints error and exits
 * - Permission denied: prints error and exits
 */
void Execvp(const char *file, char *const argv[]);

/**
 * Wait - Waits for any child process to terminate with error handling
 * @status: Location to store status information
 * Return: PID of the terminated child on success, -1 on failure
 * Corner cases:
 * - NULL status: prints error and returns -1
 * - No child processes: prints error
 */
pid_t Wait(int *status);

/**
 * Waitpid - Waits for process termination with error handling
 * @pid: Process ID to wait for
 * @status: Location to store status information
 * @options: Options for waiting
 * Return: PID of the child on success, -1 on failure
 * Corner cases:
 * - Invalid PID: prints error
 * - No child processes: prints error
 */
pid_t Waitpid(pid_t pid, int *status, int options);

/**
 * endsWith - Checks if a string ends with another string/suffix
 * @str: string to check from
 * @suffix: string/suffinx to check for in the end of str
 * Return: true if suffix is at the end and false if it isnt
 * Corner cases:
 *  - NULL argument or arguments: returns false
 *  - If suffix is longer than str: returns false
 */
bool endsWith(const char *str, const char *suffix);

#endif
