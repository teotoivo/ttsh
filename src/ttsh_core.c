#include "ttsh_core.h"
#include "ttsh_execution.h"
#include "ttsh_input.h"
#include "ttsh_prompt.h"
#include "ttsh_rawmode.h"
#include "ttsh_tokenizer.h"
#include "ttsh_utils.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void ttsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    /* Print shell prompt */
    print_prompt();
    fflush(stdout);

    enableRawMode();
    /* Read input */
    line = ttsh_read_line();
    disableRawMode();

    /* Tokenize the input */
    args = ttsh_tokenize(line);

    /* Process and execute commands */
    status = ttsh_process_and_execute(args);
    (void)status; // For now, we ignore the exit status

    free(line);
    free(args);
  } while (1);
}
