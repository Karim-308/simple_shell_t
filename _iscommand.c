#include "main.h"

/**
 * isCommand - Checks if a string is a command.
 * @com: The command string.
 * Return: Command if true, NULL if false.
 */
char *isCommand(char *com)
{
	struct stat buffer;
	char *dir = NULL;
	char *PATH = NULL;
	char *PATHcpy = NULL;
	char *filePath = NULL;
	char *retPath = NULL;
	char delimiters[] = ":";

	if (com[0] == '/')
	{
		if (stat(com, &buffer) == 0)
			return ((S_ISREG(buffer.st_mode)) ? com : NULL);
		else
			return (NULL);
	}
	PATH = _getenv("PATH", 4);
	PATHcpy = _strcpy(PATH);
	dir = strtok(PATHcpy, delimiters);
	while (dir)
	{
		filePath = _strcon(dir, com);
		if (stat(filePath, &buffer) == 0)
		{
			retPath = _strcpy(filePath);
			free(filePath);
			free(PATHcpy);
			return (retPath);
		}
		free(filePath);
		dir = strtok(NULL, delimiters);
	}
	free(PATHcpy);
	return (NULL);
}
