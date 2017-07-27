# include <ft_p.h>

int			ft_lhandle_request(char *line, int connfd)
{
	char	**argv;
	int		n;

	/*
	** return to client whether the command has been handled 
	** or should be handled by the server
	*/
	n = FALSE;
	/*
	** get command line by splitting string
	*/
	argv = ft_get_argv(line);
	/*
	** check if a built in function
	*/
	if (ft_strequ(argv[0], "lpwd"))
		ft_pwd(connfd);
	else if (ft_strequ(argv[0], "lls"))
		ft_ls(connfd);
	else if (ft_strequ(argv[0], "lcd"))
		ft_lcd(connfd, argv);
	else if (ft_strequ(argv[0], "quit"))
	{
		ft_dstrdel(argv);
		exit(0);
	}
	/*
	** check if the command has een handled locally
	*/
	if (ft_strequ(argv[0], "lpwd") || ft_strequ(argv[0], "lcd") || ft_strequ(argv[0], "lls"))
		n = TRUE;
	/*
	** free
	*/
	ft_dstrdel(argv);
	return (n);
}