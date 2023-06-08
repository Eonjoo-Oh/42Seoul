#include "pipex.h"

void	do_pid1_heredoc(t_arg *arg)
{
	close(arg->fd[0]);
	dup2(arg->temp_fd, STDIN_FILENO);
	dup2(arg->fd[1], STDOUT_FILENO);
	close(arg->temp_fd);
	close(arg->fd[1]);
	if (execve(arg->cmd1_path, arg->cmd1, NULL) == -1)
		print_error("execve failed");
}

void	do_pid2_heredoc(t_arg *arg)
{
	arg->bonusout_fd = open("arg->argv[5]", O_CREAT | O_APPEND | O_RDWR , 0644);
	close(arg->fd[1]);
	dup2(arg->fd[0], STDIN_FILENO);
	dup2(arg->bonusout_fd, STDOUT_FILENO);
	close(arg->fd[0]);
	close(arg->outfile_fd);
	if (execve(arg->cmd2_path, arg->cmd2, NULL) == -1)
		print_error("execve failed");
}

void	do_cmd_heredoc(t_arg *arg)
{
	pid_t	pid1;
	pid_t	pid2;

	pipe(arg->fd);
	pid1 = fork();
	if (pid1 == 0)
		do_pid1_heredoc(arg);
	pid2 = fork();
	if (pid2 == 0)
		do_pid2_heredoc(arg);
	close(arg->fd[0]);
	close(arg->fd[1]);
	waitpid(pid1, 0, 0);
	waitpid(pid2, 0, 0);
}

void	get_input_heredoc(t_arg *arg)
{
	char	*str;

	arg->temp_fd = open("temp", O_CREAT | O_APPEND | O_RDWR, 0644);
	while (1)
	{
		str = get_next_line(0);
		if (strncmp(str, arg->limiter, ft_strlen(arg->limiter)) == 0)
			break ;
		write (arg->temp_fd, str, ft_strle(str));
		free(str);
		//temp라는 파일 또는 pipe에 이어서 계속 쓰기
	}//bonust t_arg를 선언해서 새로운 타입을 만들어주자
	free(str);
	close(arg->temp_fd);
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

int heredoc_main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	char	*str;

	if (argc != 6)
		exit(1);
	arg = init_heredoc(&arg, argc, argv, envp);
	get_input_heredoc(&arg); //heredoc으로 입력받은 내용을 임시파일에 저장한다.
	do_cmd_bonus(&arg);
}

// ./pipex here_doc LIMITER cmd cmd1 file
// cmd << LIMITER | cmd1 >> outfile