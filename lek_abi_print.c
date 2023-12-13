#include "shell.h"

/**
  * lek_abi_print - to print  for lekan and abioye project;
  *
  * @message: the message
  *
  * return 0;
  */


void lek_abi_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
