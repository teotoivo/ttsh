#ifndef TTSH_TOKENIZER_H
#define TTSH_TOKENIZER_H

#define TTSH_TOKEN_BUFFSIZE 64
#define TTSH_TOKEN_DELIM " \t\r\n\a"
/**
 * ttsh_tokenize - Splits a line into tokens.
 * @line: The input line.
 *
 * @return A NULL-terminated array of tokens. The caller is responsible for
 * freeing the memory.
 */
char **ttsh_tokenize(char *line);

#endif
