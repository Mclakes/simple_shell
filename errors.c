#include "main.h"

/**
 * print_error - prints error messages to standard error
 * @vars: the pointer to struct of variables
 * @msg: the message to print out
 *
 * Return: void
 */
void print_error(vars_t *vars, char *msg)
{
	char *count;

	_puts2(vars->argv[0]);
	_puts2(": ");
	count = _uitoa(vars->count);
	_puts2(count);
	free(count);
	_puts2(": ");
	_puts2(vars->av[0]);
	if (msg)
	{
		_puts2(msg);
	}
	else
		perror("");
}

/**
 * _puts2 - function that prints a string to standard error
 * @str: the string to print
 *
 * Return: void
 */
void _puts2(char *str)
{
	ssize_t n, len;

	n = _strlen(str);
	len = write(STDERR_FILENO, str, n);
	if (len != n)
	{
		perror("Fatal Error");
		exit(1);
	}

}

/**
 * _uitoa - converts an unsigned int to a string
 * @count: the unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int temp, digits;

	temp = count;
	for (digits = 0; temp != 0; digits++)
		temp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
