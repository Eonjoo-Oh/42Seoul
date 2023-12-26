#include <unistd.h>
#include <sys/types.h>
int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

int	print_err(char *msg)
{
	int	len = ft_strlen(msg);

	write(2, msg, len);
	return (1);
}

int	print_err_path(char *msg, char *path)
{
	int	msg_len = ft_strlen(msg);
	int	path_len = ft_strlen(path);

	write(2, msg, msg_len);
	write(2, path, path_len);
	write(2, "\n", 1);
	return (1);
}

int	exec_cd(char **argv, int i)
{
	if (i != 2)
		return (print_err("error: cd: bad arguments\n")); // 1;
	if (chdir(argv[1]) == -1)
		return (print_err_path("error: cd: cannot change directory to "), argv[1]);
	return (0);
}//chdir이 실패, cd 뒤에 argv가 없거나 더 많은 경우

int exec(char **argv, char **envp, int i)
{
	//fork, pipe, dup2, waitpid
	int	fd[2];
	int	is_pipe = 0;
	int	return_value = 0;
	int	status;

	if (argv[i] && strcmp(argv[i], "|") == 0)
		is_pipe = 1;
	int	pid = fork();
	if (pid == 0)
	{
		argv[i] = 0;
		if(is_pipe == 1 && dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1] == -1))
		{
			return (print_err("error: fatal\n"));
		}
		execve(*argv, argv, envp);
		return (print_err_path("error: cannot execute ", *argv));
	}
	waitpid(pid, &status, 0);
	if (is_pipe == 1)
	{
		if (dup2(fd[0], 0) == -1)
			return (print_err("error: fatal\n"));
		if (close(fd[0]) == -1)
			return (print_err("error: fatal\n"));
		if (close(fd[0] == -1))
			return (print_err("error: fatal\n"));
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
	int i = 0;
	int status = 0;
	if (argc <= 1)
		return (status);
	argv++;
	while (argv[i])
	{
		i = 0;
		while(argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;
		if (strcmp(argv[0], "cd") == 0)
			status = exec_cd(argv, i);
		else
			status = exec(argv, envp, i);
		argv += i + 1;
	}
	return (status);
}
	// ./microshell ls -l | cat -e | cd ../ adkj adjklj;
	// ++argv;
// /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell