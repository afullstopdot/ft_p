# include <ft_p.h>

void		ft_handle_request(char *line, int connfd)
{
	char	**argv;

	/*
	** get command line by splitting string
	*/
	if ((argv = ft_get_argv(line)))
	{
		/*
		** check if a built in function
		*/
		if (ft_strequ(argv[0], "pwd"))
			ft_pwd(connfd);
		else if (ft_strequ(argv[0], "cd"))
			ft_cd(connfd, argv);
		else if (ft_strequ(argv[0], "ls"))
			ft_ls(connfd);
		else
			ft_send_response("ft_p: invalid command\n", connfd);
		/*
		** free
		*/
		ft_dstrdel(argv);
	}
	else
		ft_send_response("ft_p: command not specified\n", connfd);
}