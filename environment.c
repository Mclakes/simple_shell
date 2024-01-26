#include "main.h"

/**
 * make_env - make the shell environment from the environment passed to main
 * @env: the environment passed to main
 *
 * Return: pointer to the new environment
 */
char **make_env(char **env)
{
	char **new_env = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (new_env == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	i = 0;
	while (env[i] != NULL)
	{
		new_env[i] = _strdup(env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

/**
 * free_env - functtion that free the shell's environment
 * @env: the shell's environment
 *
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}

	free(env);
}
