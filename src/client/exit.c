#include <ft_p.h>

void	ft_check_exit(char *line)
{
	char	**argv;

	argv = NULL;
	if (line)
	{
		argv = ft_get_argv(line);
		if (ft_strequ(argv[0], "exit"))
		{
			exit(EXIT_SUCCESS);
		}
	}
}