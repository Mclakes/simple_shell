#include "shell.h"

/**
 * to_exit - exits the shell with or without a return of status x & n
 *
 * @arv: array of words of the entered line
 */

void to_exit(char **arv)
{
	int x, n;

	if (arv[1])
	{
		n = _atoi(arv[1]);
		if (n <= -1)
			n = 2;
		free_arv(arv);
		exit(n);
	}
	for (x = 0; arv[x]; x++)
		free(arv[x]);
	free(arv);
	exit(0);
}

/**
 * _atoi - converts a strng to an integer
 *@s: pointer to a string
 *Return: the integer
 */
int _atoi(char *s)
{
	int i, num, sign = 1;

	i = 0;
	num = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		num = (num * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (num);
}

/**
 * envr - to print to the current environment
 * @arv: array of arguments
 */
void envr(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}

}

/**
 * _setenv - Initite a new environ or check existing one
 * @arv: array of entered words
 */
void _setenv(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(_getenvr("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = concat_all(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * _unsetenv - to elininate an environment variable
 * @arv: array of entered words
 */
void _unsetenv(char **arv)
{
	int i, j;

	if (!arv[1])
	{
		perror(_getenvr("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
