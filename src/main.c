#include "ttsh_config.h"
#include "ttsh_core.h"
#include <stddef.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  // Load config files
  load_config();

  // Run command loop
  ttsh_loop();
  // Perform shutdown/cleanup

  return EXIT_SUCCESS;
}
