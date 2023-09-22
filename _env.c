#include "main.h"


/**
 * printEnv - prints the environment variables.
 */
void printEnv(void)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);
		_putchar('\n');
	}
}

/**
 * _getenv - gets the environment variable's value.
 * @name: name of the environment variable.
 * @length: length of the name.
 * Return: value of the environment variable.
 */
char *_getenv(char *name, int length)
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
 * _getenvVar - gets the environment variable's adres.
 * @name: name of the environment variable.
 * @length: length of the name.
 * Return: value of the environment variable.
 */
char *_getenvVar(char *name, int len)
{
    int i;
    for (i = 0; environ[i]; i++)
    {
        if (_strcmpn(environ[i], name, len))
            return (environ[i]);
    }
    return (NULL);
}
