#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	unsigned char	*s_str;
	size_t			i;

	i = 0;
	d_str = (unsigned char *)dest;
	s_str = (unsigned char *)src;
	if (d_str == 0 && s_str == 0)
		return (0);
	if (d_str < s_str)
	{
		while (i++ < n)
		{
			d_str[i] = s_str[i];
		}
	}
	else
	{
		while (n - i > 0)
		{
			d_str[n - i - 1] = s_str[n - i - 1];
			i++;
		}
	}
	return (dest);
}

int	main(void)
{
	char str[10] = "123456";
	ft_memmove(&(str[1]), str, 3);
	printf("%s", str);
}	
/*
dest = 456789
src = 123456789
원하는값 = 123123489
ft_memcpy에서 나오는 값 = 123123189 -> 4가 이미 1로 바뀌어서 그런듯
memmove에서는 이걸 해소하기위해 buffer에 복사한다음 옮겨야한다는데 buffer에 복사하고 싶은 부분을/
옮겨놓고 복사하면 될 것 같다 
복사하고 싶은 부분은 어떻게 옮기지? -> src와 size가 있으니 옮길 수 있을듯?
*/