#include "main.h"

char **global_argv = NULL;
int child_exit_status = 0;

/**
 * shell_loop - The main shell loop.
 * Return: void.
 */
void shell_loop(void)
{
	ssize_t bytes;
	char *line = NULL;
	size_t length;
	char *command = NULL, *commNumStr = NULL;
	int interactive = isatty(STDIN_FILENO), commNum = 0;
	char **args = NULL;

	while (1)
	{
		commNum++;
		if (interactive)
			write(STDOUT_FILENO, "($) ", 5);
		bytes = getline(&line, &length, stdin);
		if (bytes == -1)
		{
			if (!interactive)
				break;
			_putchar('\n');
			break;
		}
		if (bytes != 1)
			process_command(line, bytes, commNum);
		free(line);
	}
}

/**
 * process_command - Processes the command entered by the user.
 * @line: The command line.
 * @bytes: Number of bytes read.
 * @commNum: Command number.
 * Return: void.
 */
void process_command(char *line, ssize_t bytes, int commNum)
{
	char **args;
	char *command, *commNumStr;

	args = split_line(line, bytes);
	if (!args)
		return;

	if (_strcmp(args[0], "exit"))
	{
		_exitFromShell(args, line, global_argv);
		free(args);
		return;
	}
	                 
 	if (_strcmp(args[0], "cd"))
	
	{
		commNumStr = _intToStr(commNum);
		_cd(args, line,global_argv, commNumStr);/*&p, &c, &t*/
		free(args);
		free(commNumStr);
		return;
	}


	if (_strcmp(args[0], "env"))
	{
		free(args);
		printEnv();
		return;
	}

	command = isCommand(args[0]);
	if (command)
		execute_command(command, args);
	else
	{
		commNumStr = _intToStr(commNum);
		_perror(6, ": ", commNumStr, ": ", args[0], ": not found\n");
		free(commNumStr);
	}
	free(args);
}

/**
 * execute_command - Executes the command using fork and exec.
 * @command: The command to execute.
 * @args: The command arguments.
 * Return: void.
 */
void execute_command(char *command, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		_perror(1, "Failed to fork\n");
		return;
	}
	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			_perror(3, args[0], ": not found\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);

	if (command != args[0])
		free(command);
}

/**
 * main - Entry point for the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @envp: Environment pointer.
 * Return: 0 on success.
 */
int main(int argc, char *argv[], char *envp[])
{
	global_argv = argv;

	if (argc != 1)
	{
		perror("Usage: ./shell\n");
		return (EXIT_FAILURE);
	}

	shell_loop();

	return (0);
}

