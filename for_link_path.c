#include "shell.h"


/**
 * _getenvr - gets the quaantity of the global variable
 *
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenvr(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}


/**
 * add_node_end - adds a new node at the finished list
 * @head: pointer to pointer to the linked list
 * @str: pointer to string in prev first node
 * Return: address of the new element/node
 */

list_path *add_node_end(list_path **head, char *str)
{

	list_path *tmp;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}


/**
 * linkpath - creates a linked to path directories
 * @path: string of path value checked
 * Return: points to created linked list
 */
list_path *linkpath(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _which - finds the name of the path of the file's name
 * @filename: name of file or command typed
 * @head: path directories head of linked list
 * Return: pathname of filename or NULL if no match
 */
char *_which(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

	while (tmp)
	{

		string = concat_all(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * to_free_list - to_frees a list_t
 *@head: pointer to our linked list
 */
void to_free_list(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}

}
