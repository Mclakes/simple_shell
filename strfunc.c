#include "main.h"

/**
 * _strlen - the function that checks the lenght of a string
 * @str: the string
 * Return: the length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _puts - writes a string to standard output
 * @str: the string to write
 *
 * Return: the number of chars printed or -1 on failure
 */
ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * _strdup - duplicates a string
 * @strtodup: the string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *strtodup)
{
	char *strdup;

	int len, i;

	if (strtodup == 0)
		return (NULL);

	len = _strlen(strtodup);
	strdup = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		strdup[i] = strtodup[i];

	return (strdup);
}

/**
 * _strcmpr - compares two strings
 * @strcmp1: the first string to be compared in length
 * @strcmp2: the second string to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	for (i = 0; strcmp1[i] == strcmp2[i]; i++)
	{
		if (strcmp1[i] == '\0')
		{	break;
			return (0);
		}
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _strcat - concatenates two strings
 * @str1: the first string
 * @str2: the second string
 * Return: a pointer to the concatenated string
 */
char *_strcat(char *str1, char *str2)
{
	char *strcat;
	unsigned int len1, len2, len, i, j;

	len1 = 0;
	len2 = 0;
	if (str1 == NULL)
		len1 = 0;
	else
	{
		for (; str1[len1]; len1++)
			;
	}
	if (str2 == NULL)
		len2 = 0;
	else
	{
		for (; str2[len2]; len2++)
			;
	}
	len = len1 + len2 + 2;
	strcat = malloc(len * sizeof(char));
	if (strcat == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		strcat[i] = str1[i];
	strcat[i] = '/';
	for (j = 0; j < len2; j++)
		strcat[i + 1 + j] = str2[j];
	strcat[len1 + len2 + 1] = '\0';
	return (strcat);
}
