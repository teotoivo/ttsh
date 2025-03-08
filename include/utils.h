#ifndef UTILS_H
#define UTILS_H

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

#define p(...) printf(__VA_ARGS__)
#define ERROR(msg) fprintf(stderr, COLOR_RED msg COLOR_RESET "\n")
#define TTSH_TOKEN_DELIM "\t\n\v\f\r "
#define TTSH_TOKEN_BUFFSIZE 64

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

#endif
