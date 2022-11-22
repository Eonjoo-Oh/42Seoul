#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*s_str;
	size_t			i;

	s_str = (const char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = s_str[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	const char		*s_str;
	char			*tmp;
	size_t			i;

	tmp = dest;
	d_str = (unsigned char *)dest;
	s_str = (const char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	ft_memcpy(tmp, src, n);
	while (i < n)
	{
		d_str[i] = tmp[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char src[10] = "123456789";
	ft_memmove(&(src[3]), src, 4 * sizeof(char));
	printf("%s", src);
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