#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;

	if (argc < 5)
		return (0);

	cmd1 = find_cmd(envp, argv[2]);
	do_cmd(argv[1], cmd1);
	do_pipe(infile, argv[2], envp);


}