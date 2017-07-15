#include <ft_p.h>

void	ft_check_exit(char *line)
{
	char	**argv;

	argv = NULL;
	if (line)
	{
		argv = ft_get_argv(line);
		if (ft_strequ(argv[0], "quit"))
		{
			ft_dstrdel(argv);
			exit(EXIT_SUCCESS);
		}
		ft_dstrdel(argv);
	}
}