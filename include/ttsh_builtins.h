#ifndef TTSH_BUILTINS_H
#define TTSH_BUILTINS_H

int ttsh_cd(char **args);
int ttsh_help(char **args);
int ttsh_exit(char **args);

typedef int (*builtin_func_t)(char **args);

typedef struct builtin_command {
  char *name;
  builtin_func_t function;
} builtin_command;

extern builtin_command builtins[];

/**
 * ttsh_num_builtins - Gets the number of builtin functions
 * return: Number of builtins
 */
int ttsh_num_builtins();

#endif // !TTSH_BUILTINS_H
