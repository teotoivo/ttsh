#ifndef TTSH_EXECUTION_H
#define TTSH_EXECUTION_H

/**
 * ttsh_launch - Runs a command in a child process.
 * @args: Array of command arguments.
 *
 * @return The status of the executed command.
 */
int ttsh_launch(char **args);

/**
 * ttsh_execute - Executes a command, either as a built-in or by launching a
 * process.
 * @args: Array of command arguments.
 *
 * @return The exit status.
 */
int ttsh_execute(char **args);

/**
 * count_args - Counts the number of arguments in a token array.
 * @tokens: The token array.
 *
 * @return The count of tokens.
 */
int count_args(char **tokens);

/**
 * ttsh_process_and_execute - Processes command tokens and handles logical
 * operators.
 * @args: Array of tokens.
 *
 * @return The exit status of the last executed command.
 */
int ttsh_process_and_execute(char **args);

#endif
