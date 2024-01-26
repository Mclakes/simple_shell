#include "main.h"

/**
 * _realloc - function that reallocates a pointer to double the space
 * @ptr: the pointer to the old array
 * @size: the pointer to number of elements in the old array
 *
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new_mem;
	size_t i;

	new_mem = malloc(sizeof(char *) * ((*size) + 10));
	if (new_mem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new_mem[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new_mem);
}
