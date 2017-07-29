#include <libftp.h>

/*
** strjoin wrapper that expects pointer that points
** to dst must be freed
*/

char		*ft_wstrjoin(char *dst, char *src)
{
	char 	*final;

	final = NULL;
	if (dst && src)
	{
		final = ft_strjoin(dst, src);
		ft_strdel(&dst);
	}
	return (final);
}