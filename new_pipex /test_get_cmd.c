#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_arg	test;
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;

	if (argc == 0 || argv == 0 || envp == 0)
		return (0);
	test = init_arg(&test, argc, argv, envp);
	test.order = 1;
	cmd = get_cmd(argv[1]);
	cmd_path = get_cmd_path(&test, cmd[0]);

	printf("cmd_path : %s\n", cmd_path);
	printf("cmd : \n");
	while (cmd[i])
	{
		printf("%s\n", cmd[i]);
		i++;
	}
}
//gcc -g test_get_cmd.c get_cmd.c ft_split.c pipex_utils.c init_arg.c