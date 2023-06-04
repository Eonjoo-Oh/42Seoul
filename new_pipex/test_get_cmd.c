#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_arg	test;
	int		i;

	i = 0;

	if (argc == 0 || argv == 0 || envp == 0)
		return (0);
	test = init_arg(&test, argc, argv, envp);
	test.order = 1;
	get_cmd(&test);
	get_cmd_path(&test);

	printf("cmd_path : %s\n", test.cmd_path);
	printf("cmd : \n");
	while (test.cmd[i])
	{
		printf("%s\n", test.cmd[i]);
		i++;
	}
}
//gcc -g test_get_cmd.c get_cmd.c ft_split.c pipex_utils.c init_arg.c