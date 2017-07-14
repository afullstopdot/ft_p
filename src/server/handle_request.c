# include <ft_p.h>

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

void		ft_handle_request(char *line, int connfd, char *root)
{
	char	**argv;
	char	buff[MAXLINE];

	/*
	** get command line by splitting string
	*/

	argv = ft_get_argv(line);
	ft_bzero(buff, MAXLINE);
	ft_bzero(root, ft_strlen(root)); //to avoid unused var variable, to be used for cd
	if (ft_strequ(argv[0], "pwd"))
		ft_pwd(buff);
	else
		ft_invalid(buff);
	ft_send_response(buff, connfd);
}