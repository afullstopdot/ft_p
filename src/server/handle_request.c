# include <ft_p.h>

void		ft_handle_request(char *line, int connfd)
{
	char	**argv;

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
		ft_pwd();
	else if (ft_strequ(argv[0], "cd"))
		ft_cd(argv);
	else if (ft_strequ(argv[0], "ls"))
		ft_ls();
	else
		ft_invalid();

	/*
	** using buff send response to client
	*/

	ft_send_response(buff, connfd);

	/*
	** free
	*/

	ft_dstrdel(argv);
}