#include "shell.h"

/**
  * main - The running program
  *
  * Return: 0 on successful execution, non-zero otherwise.
  */

int main(void)
{
	char command[120];

	while (true)
	{
		display_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}

	return (0);
}

