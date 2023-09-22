#include "main.h"

extern char **environ;

/**
 * _getenv2 - Get an environment variable.
 * @name: Name of the environment variable.
 * @length: Length of the name.
 * Return: Value of the environment variable.
 */
char *_getenv2(char *name, int length)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strcmpn(environ[i], name, length))
			return (environ[i] + length + 1);
	}
	return (NULL);
}

/**
 * copy - copies from loc to another
 * @to: to string
 * @from: from string
 * Return: nothing
 */
void copy(char (*to)[128], char (*from)[128])
{
	int i = 0;

	while ((*from)[i])
	{
		(*to)[i] = (*from)[i];
		i++;
	}
	(*to)[i] = '\0';
}

/**
 * _cd - change dir
 * @args: args array
 * @line: command line
 * @argv: argv of the shell
 * @commNum: command line number
 * Return: nothing
 */
void _cd(char **args, __attribute__((unused)) char *line,
		__attribute__((unused)) char *argv[], char *commNum)
{
	char home[128], *homeTemp = NULL;
	static char prev[128], curr[128], temp[128];
	int i = 0;

	if (_strToInt(commNum) == 1)
	{
		getcwd(prev, 128);
		getcwd(curr, 128);
		getcwd(temp, 128);
		homeTemp = _getenv2("HOME", 4);
		for (i = 0; homeTemp[i]; i++)
			home[i] = homeTemp[i];
		home[i] = '\0';
	}
	getcwd(curr, 128);
	if (!args[1])
	{
		chdir(home);
		copy(&prev, &curr);
		copy(&curr, &home);
		return;
	}
	if (args[1][0] == '-' && !args[1][1])
	{
		copy(&temp, &prev);
		copy(&prev, &curr);
		copy(&curr, &temp);
		chdir(curr);
		_puts(2, curr, "\n");
		return;
	}
	copy(&temp, &prev);
	copy(&prev, &curr);
	if (chdir(args[1]) != 0)
	{
		copy(&prev, &temp);
		_perror(6, argv[0], ": ", commNum,
				": cd: can't cd to ", args[1], "\n");
		return;
	}
	getcwd(curr, 128);
}

