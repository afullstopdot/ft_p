# include <ft_p.h>

void		ft_send_response(char *buff, int connfd)
{
	if (buff)
	{
		ft_wwriten(connfd, buff, MAXLINE);
	}
	else
	{
		ft_err_quit("ft_send_response fail");
	}
}

void		ft_handle_request(char *line, int connfd)
{
	char	**argv;
	char	buff[MAXLINE];

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

	if (ft_strequ(argv[0], "pwd"))
		ft_pwd(buff);
	else if (ft_strequ(argv[0], "cd"))
		ft_cd(buff, argv);
	else if (ft_strequ(argv[0], "ls"))
		ft_ls(buff);
	else
		ft_invalid(buff);

	/*
	** using buff send response to client
	*/

	ft_send_response(buff, connfd);

	/*
	** free
	*/

	ft_dstrdel(argv);
}