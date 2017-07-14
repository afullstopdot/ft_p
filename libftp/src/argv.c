#include <libftp.h>

char		**ft_get_argv(char *line)
{
	char	**argv;

	argv = NULL;
	if (line)
	{
		if ((argv = ft_strsplit(line, ' ')))
		{
			if (ft_dstrlen(argv) > 0)
			{
				return (argv);
			}
		}
	}
	ft_err_quit("ft_get_argv fail");
	return (argv);
}