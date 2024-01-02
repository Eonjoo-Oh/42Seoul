# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
#include <stdio.h>

// strcmp return 0 if two string are same.

int print_error(char* error_message)
{
	while (*error_message != '\0')
		write(2, error_message++, 1);
	return 1;
}

int cd(char **av, int index)
{
	if (index != 2)
		return print_error("error: cd: bad arguments\n");
	if (chdir(av[1]) == -1)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(av[1]);
		return print_error("\n");
	}
	return 0;
}

int execute_command(char** av, char** ev, int index)
{
	int fd[2];
	int status;
	int is_pipe;
	int pid;

	is_pipe = (av[index] != NULL && strcmp(av[index], "|") == 0);
	if (is_pipe == 1 && pipe(fd) == -1)
		return print_error("error: fatal\n");
	pid = fork();
	if (pid == 0)
	{
		av[index] = NULL;
		if ((is_pipe == 1) && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return print_error("error: fatal\n");
		execve(*av, av, ev);
		print_error("error: cannot execute ");
		print_error(*av);
		return print_error("\n");
	}
	waitpid(pid, &status, 0);
	if (is_pipe == 1 && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return print_error("error: fatal\n");
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char** av, char** ev)
{
	int status = 0;
	int index;

	if (ac > 1)
	{
		++av;
		while (*av != NULL)
		{
			index = 0;
			while (av[index] != NULL && strcmp(av[index], "|") != 0 && strcmp(av[index], ";") != 0)
				++index;
			if (strcmp(*av, "cd") == 0)
				status = cd(av, index);
			else if (index != 0)
				status = execute_command(av, ev, index);
			if (index == 0)
				av += 1;
			av += index;
		}
	}
	return status;
}