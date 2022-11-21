#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char dst[] = "abcd";
	char src[] = "zs";
	memcpy(dst, src, 0);
	printf("%s", dst);
	return (0);
}

