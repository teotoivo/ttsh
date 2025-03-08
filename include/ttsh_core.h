#ifndef TTSH_CORE_H
#define TTSH_CORE_H

/**
 * ttsh_loop - Main loop for the shell
 */
void ttsh_loop(void);

/**
 * ttsh_read_line - Reads a line of input from stdin.
 *
 * Uses Getline to read a line, handling memory allocation.
 *
 * @return A pointer to the line read from stdin.
 *         The caller is responsible for freeing the memory.
 */
char *ttsh_read_line(void);

/**
 * ttsh_tokenize - Tokenizes a string into an array of tokens.
 * @line: The string to tokenize.
 *
 * Uses strtok to split the string into tokens based on
 * TTSH_TOKEN_DELIM. Allocates memory for the tokens array,
 * reallocating as needed.
 *
 * @return A pointer to a null-terminated array of tokens.
 *         The caller is responsible for freeing the memory.
 */
char **ttsh_tokenize(char *line);

/**
 * lsh_launch - Runs a command in a child process.
 * @args: Array of strings: command to run and its arguments.
 *       (args[0] is the command).
 *
 * Forks a process, executes the command in the child,
 * and waits for the child to finish.  Always returns 1.
 */
int ttsh_launch(char **args);

int ttsh_execute(char **args);

#endif
