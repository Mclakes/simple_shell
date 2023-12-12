#include "shell.h"

void lek_abi_print(const char *message) {
    write(STDOUT_FILENO, message, strlen(message));
}
