#include <libftp.h>

int			ft_dstrlen(char **str)
{
	int		len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}