#include "shell.h"

/**
 * c_handler - checks if ctrl c is clicked
 * @sig_num: int
 */
void c_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#beautyC$ ");
	}
}

/**
* _EOF - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isatty - verif if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#beautyC$ ");
}
/**
 * main - the mainShell
 * Return: 0 on success
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, c_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = splitstring(buff, " \n");
		if (!arv || !arv[0])
			to_execute(arv);
		else
		{
			value = _getenvr("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			f = checkingbuild(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				to_execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				to_execute(arv);
			}
		}
	}
	to_free_list(head);
	free_arv(arv);
	free(buff);
	return (0);
}
