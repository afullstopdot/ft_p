# include <ft_p.h>

void		ft_send_lresponse(char *buff, int connfd, int print)
{
	if (buff)
	{

		/*
		** check if we are about to print an empty string
		*/

		if (print)
		{
			ft_wwriten(connfd, buff, MAXLINE);
			ft_putchar('\n');
		}
	}
	else
	{
		ft_err_quit("ft_send_response fail");
	}
}

int			ft_lhandle_request(char *line, int connfd)
{
	char	**argv;
	char	buff[MAXLINE];
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
	** clear buff
	*/

	ft_bzero(buff, MAXLINE);

	/*
	** check if a built in function
	*/

	if (ft_strequ(argv[0], "lpwd"))
		ft_pwd(buff);
	else if (ft_strequ(argv[0], "lls"))
		ft_ls(buff);
	else if (ft_strequ(argv[0], "lcd"))
		ft_lcd(buff, argv);
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
	** using buff send response to client
	*/

	ft_send_lresponse(buff, connfd, n);

	/*
	** free
	*/

	ft_dstrdel(argv);

	return (n);
}