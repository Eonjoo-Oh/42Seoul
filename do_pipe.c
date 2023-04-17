do_pipe(int fd, char *cmd, char **envp)
{
	cmd = execve(which, cmd);

}