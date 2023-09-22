#include "main.h"

/**
 * split_line - Splits a line into words.
 * @line: The line.
 * @bufsize: The buffer size.
 * Return: Tokens.
 */
char **split_line(char *line, int bufsize)
{
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("simple_shell: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;

	if (position == 0)
	{
		free(tokens);
		return (NULL);
	}
	return (tokens);
}
