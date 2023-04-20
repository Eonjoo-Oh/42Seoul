#include "pipex.h"

#include <fcntl.h>
#include <unistd.h>

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
}