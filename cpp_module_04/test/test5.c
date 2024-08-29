#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	ft_strlen(char *msg)
{
	int i = 0;
	while (msg[i])
	{
		i++;
	}
	return (i);
}

int	print_error(char *msg)
{
	int	msg_len;

	if (!msg)
		return (1);
	msg_len = ft_strlen(msg);
	write(2, msg, msg_len);
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		print_error("error: cd: bad arguments\n");
	if (chdir(argv[1]) == -1)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(*argv);
		return (print_error("\n"));
	}
	return (0);
}

int	execve_cmd(char **argv, char **envp, int i)
{
	int	status;
	int	pid;
	int	is_pipe = 0;
	int	fd[2];

	if (argv[i] != NULL && strcmp(argv[i], "|") == 0)
		is_pipe = 1;
	if (is_pipe == 1 && pipe(fd) == -1)
		return(print_error("error: fatal\n"));
	pid = fork();
	if (pid == 0)
	{
		argv[i] = NULL;
		if (is_pipe == 1 && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return(print_error("error: fatal\n"));
		execve(*argv, argv, envp);
		print_error("error: cannot execute ");
		print_error(*argv);
		return (print_error("\n"));
	}
	waitpid(pid, &status, 0);
	if (is_pipe == 1 && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return(print_error("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
	int	i;
	int	status = 0;

	if (argc <= 1)
		return (status);
	argv++;
	while(*argv != NULL)
	{
		i = 0;
		while (argv[i] != NULL && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
		{
			i++;
		}
		if (strcmp(*argv, "cd") == 0)
			status = cd(argv, i);
		else if (i != 0)
			status = execve_cmd(argv, envp, i);
		if (i == 0)
			argv++;
		argv += i;
	}
}