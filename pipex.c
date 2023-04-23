#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	if (argc != 5)
		return (0);

	arg.path = get_path(envp);
	arg.infile_fd = open(argv[1], O_RDONLY);
	arg.outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	arg.cmd1 = get_cmd(argv[2]);
	arg.cmd2 = get_cmd(argv[3]);
	arg.cmd1_path = get_cmd_path(arg, 1);
	arg.cmd2_path = get_cmd_path(arg, 2);//여기까지 명령어 파싱부분

	do_cmd1(arg);
	//마지막으로 파일을 닫거나 파이프 종료시켜야한다? 그리고 wait도 써야될듯?
	/*printf("%s\n", arg.cmd1_path);
	printf("%s\n", arg.cmd2_path);
	
	fd = do_cmd(argv[1], cmd1);//이쯤에서 fodrk를 써야된다.
	do_pipe(fd, cmd2, argv[4]);*/
}