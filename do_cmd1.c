#include "pipex.h"

void	do_cmd1(t_arg arg)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();

	if (pid == 0)//자식프로세스 일 때
	{
		dup2(fd[1], STDIN_FILENO);
		dup2(arg.outfile_fd, STDOUT_FILENO);
		execve(arg.cmd2_path, arg.cmd2, NULL);
	}
	else//부모 프로세스 일 때
	{
		dup2(arg.infile_fd, 0);
		dup2(fd[1], STDOUT_FILENO);
		close(arg.infile_fd);
		close(fd[1]);
		execve(arg.cmd1_path, arg.cmd1, NULL);
		waitpid(pid, NULL, 0);
	}
}

//./pipex infile "ls" "wc -l" outfile
/*
int	do_cmd(char *infile, char *cmd)
{
	int		infile_fd;
	int		temp_fd;
	pid_t	pid;

	//infile의 fd를 찾아야 됨
	infile_fd = open(infile, O_RDONLY);
	dup2(0, infile_fd);//infile을 표준입력으로 바꿔줌
	temp_fd = open("./temp.txt", O_CREAT | O_RDWR);
	pid = fork();
	if (pid == 0)
	{
		dup2(1, temp_fd);
		execve(cmd, STDIN_FILENO, NULL);//이렇게 하면 표준입력은 infile로 받고 표준출력이 fd에 적힐 것 같음
	}
	return (temp_fd);
}*/