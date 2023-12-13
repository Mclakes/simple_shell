#include "shell.h"


/**
 * splitstring - splits a string and contert array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **splitstring(char *str, const char *delim)
{
	int n, wn;
	char **array;
	char *token;
	char *copy;

	copy = malloc(_strlen(str) + 1);
	if (copy == NULL)
	{
		perror(_getenvr("_"));
		return (NULL);
	}
	n = 0;
	while (str[n])
	{
		copy[n] = str[n];
		n++;
	}
	copy[n] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	n = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = _reallocate(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
		array[n] = _strdup(token);
		n++;
		wn++;
	}
	free(copy);
	return (array);
}

/**
 * to_execute - for execution of command
 * @argv: array of arguments
 */

void to_execute(char **argv)
{

	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(_getenvr("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * _reallocate - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void *_reallocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *current;
	char *former;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	current = malloc(new_size);
	former = ptr;
	if (current == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			current[i] = former[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			current[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			current[i] = former[i];
		free(ptr);
	}
	return (current);
}

/**
 * free_arv - frees the array of pointers in arv
 *@arv: array of pointers
 */

void free_arv(char **arv)
{
	int x;

	for (x = 0; arv[x]; x++)
		free(arv[x]);
	free(arv);
}
