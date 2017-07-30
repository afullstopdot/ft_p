# include <ft_p.h>

int			ft_handle_special(char *line, int connfd)
{
	char	**argv;
	int		result;

	result = FALSE;
	/*
	** get command line by splitting string
	*/
	if ((argv = ft_get_argv(line)))
	{
		/*
		** check if a built in function
		*/
		if (ft_strequ(argv[0], "put"))
			ft_client_put(connfd, argv);
		else if (ft_strequ(argv[0], "get"))
			ft_client_get(connfd, argv);
		/*
		** tell client if the command hs been handled here
		*/
		if (ft_strequ(argv[0], "put") || ft_strequ(argv[0], "get"))
			result = TRUE;
		/*
		** free
		*/
		ft_dstrdel(argv);
	}
	else
		ft_putstr("ft_p: \033[0;33mcommand not specified\033[0m\n");
	return (result);
}