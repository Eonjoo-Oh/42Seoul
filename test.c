#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	const char *str = "abcdcde";
	const char *str2 = "cd";
	char *result = strnstr(str, str2, 7);
	printf("%s\n", result);

	return (0);
}