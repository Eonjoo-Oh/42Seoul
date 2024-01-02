int	execve_cmd(char **argv, char **envp, int i)
{
	int	fd[2];
	int	pid;
	int	status;
	int	is_pipe = 0;

	if (argv[i] != NULL && strcmp(argv[i], "|") == 0)
		is_pipe = 1;
	if (is_pipe == 1 && pipe(fd) == -1)
		print_error("error : fatal\n");
	pid = fork();
	if (pid == 0)
	{
		argv[i] = NULL;
		if (is_pipe == 1 && (dup2(fd[1], 1) == -1 , close(fd[0]) == -1, close(fd[1]) == -1))
			print_error("error : fatal\n");
		execve(*argv, argv, envp);
		print_error("error : cannot execute ");
		print_error(*argv);
		return (print_error("\n"));
	}
	waitpid(pid, &status, 0);
	if (is_pipe == 1 && (dup2(fd[0], 0) == -1, close(fd[0]) == -1, close(fd[1]) == -1))
		print_error("error : fatal\n");
	return (WIFEXITED(status) && WEXITSTATUS(status));
}
