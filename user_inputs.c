#include "shell.h"

/**
  * read_command - this function is to read the command inputted
  *
  * @command: the comand input
  * @size: quantity of command
  *
  * return: void
  */


void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			lek_abi_print("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			lek_abi_print("Error while reading input.\n");
		exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0'; /* Remove newline */
}
