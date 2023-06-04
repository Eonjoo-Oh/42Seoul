#include "pipex.h"
char	*get_cmd_path_bonus(char *cmd, char **path)
{

}

t_arg init_heredoc(t_arg *arg, int argc, char **argv, char **envp)
{
	arg->argv = argv;
	get_path(envp, arg);
	arg->limiter = argv[2];
	arg->cmd1 = get_cmd(argv[3]);
	arg->cmd2 = get_cmd(argv[4]);
	arg->cmd1_path = get_cmd_path(arg, arg->cmd1[0]);
	arg->cmd2_path = get_cmd_path(arg, arg->cmd2[0]);
	arg->limiter = argv[2];
	arg->argc = argc;

	return (*arg);
}

void	heredoc_main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	char	*str;

	if (argc != 6)
		exit(1);
	arg = init_heredoc(&arg, argc, argv, envp);
	arg.temp_fd = open("temp", O_CREAT | O_APPEND | O_RDWR, 0644);
	while (1)
	{
		str = get_next_line(0);
		if (strncmp(str, arg.limiter, ft_strlen(arg.limiter)) == 0)
			break ;
		write (arg.temd_fd, str, ft_strle(str));
		free(str);
		//temp라는 파일 또는 pipe에 이어서 계속 쓰기
	}//bonust t_arg를 선언해서 새로운 타입을 만들어주자
	free(str);
	close(arg.temp_fd);
	do_cmd_bonus(&arg);
}

// ./pipex here_doc LIMITER cmd cmd1 file
// cmd << LIMITER | cmd1 >> outfile