#include <libftp.h>

int			ft_dstrlen(char **str)
{
	int		len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}