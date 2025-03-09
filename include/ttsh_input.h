#ifndef TTSH_INPUT_H
#define TTSH_INPUT_H

/**
 * ttsh_read_line - Reads a line of input from stdin and processes
 * continuations.
 *
 * @return A pointer to the processed input line. The caller is responsible for
 * freeing it.
 */
char *ttsh_read_line(void);

/**
 * handle_line_continuation - Processes backslash ('\') line continuations.
 *
 * @param line: The input line.
 * @return A pointer to the updated line.
 */
char *handle_line_continuation(char *line);

/**
 * handle_logical_operator_line_continuation - Processes logical operator
 * continuations ('&&' or '||').
 *
 * @param line: The input line.
 * @return A pointer to the updated line.
 */
char *handle_logical_operator_line_continuation(char *line);

#endif
