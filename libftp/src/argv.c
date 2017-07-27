#include <libftp.h>

char		**ft_get_argv(char *line)
{
	char	**argv;

	argv = NULL;
	if (line)
	{
		if (ft_empty(line))
			return (NULL);
		if ((argv = ft_strsplit(line, ' ')))
		{
			if (ft_dstrlen(argv) > 0)
				return (argv);
		}
	}
	return (argv);
}