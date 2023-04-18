#include <fcntl.h>
#include <unistd.h>

int	do_cmd(char *filename, char *cmd)
{
	char	**file;
	int		fd;
	pid_t	pid;

	file = arg_cmd(filename);
	fd = open("./temp.txt", O_CREAT | O_RDWR);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 1);
		execve(cmd, file, NULL);//이렇게 하면 이 표준출력이 fd에 적힐 것 같음
	}
	return (fd);
}