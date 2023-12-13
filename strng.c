#include "shell.h"

/**
 * _strdup - returns a ptr to a newly alloc space in mem, of  which
 * contains a copy of the str given as a parameter
 * @str: ptr to a str
 * Return: ptr to a str
 */
char *_strdup(char *str)
{
	int n, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (n = 0; n < l; n++)
	{
		new[n] = str[n];
	}
	new[l] = str[l];
	return (new);
}

/**
 * concat_all - concatenates 3 str in a newly alloc mem
 * @name: first str
 * @sep: second str
 * @value: Third str
 * Return: pointer to the new str
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _strlen - the sting length
 * @s: ptr to the str
 * Return: the length of str
 */
int _strlen(char *s)
{
	int n = 0;

	while (*(s + n) != '\0')
	{
		n++;
	}
	return (n);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a str
 * @str: pointer to str
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
