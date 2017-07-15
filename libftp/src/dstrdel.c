#include <libftp.h>

void	ft_dstrdel(char **line)
{
	int	count;

	count = 0;
	while (line[count])
	{
		ft_strdel(&line[count++]);
	}
	free(line);
}