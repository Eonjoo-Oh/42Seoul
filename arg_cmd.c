#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>

char	**make_filename(char *filename)
{
	char	**file;
	int		filename_len;
	int		i;

	file = (char **)malloc(sizeof(char *) * 2);
	if (!file)
		return ;
	file[1] = '\0';
	filename_len = strlcpy(filename);
	file[0] = (char *)malloc(sizeof(char *) * (filename_len + 1));
	if (!file[0])
		return ;
	i = 0;
	while (file[0][i])
	{
		file[0][i] = filename[i];
		i++;
	}
	return (file);
	//이 명령어를 바로 실행시키는게 아니라 이 값만 어딘가 저장해놓고 싶다.
	// 일단 exec family에 대해 공부해봐야할듯->dup(2)로 가능
}//makefilename for do_cmd