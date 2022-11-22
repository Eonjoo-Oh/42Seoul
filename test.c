#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char src[10] = "1234512345";
	char find[10] = "1234512345";
	char *result;

	result = strnstr(src, find, 10 * sizeof(char));
	printf("%s", result);
}
