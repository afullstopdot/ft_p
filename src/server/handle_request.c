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
			ft_send_response("ft_p: \033[0;31minvalid command\n\033[0m", connfd);
		/*
		** free
		*/
		ft_dstrdel(argv);
	}
	else
		ft_send_response("ft_p: \033[0;33mcommand not specified\033[0m\n", connfd);
}