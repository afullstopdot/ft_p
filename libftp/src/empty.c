#include <libftp.h>

static int			ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f');
}

int		ft_empty(char *line)
{
	int	count;
	int	size;

	count= 0;
	size = 0;
	while (line[count])
	{
		if (ft_isspace(line[count]))
			size++;
		count++;
	}
	return (size == count);
}