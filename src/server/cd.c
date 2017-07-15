# include <ft_p.h>

/*
** Change the server directory
*/

void		ft_cd(char *buff, char **argv)
{
	char	*resp;
	char	*path;
	char	*home;
	char	pwd[MAXLINE];

	resp = NULL;
	path = NULL;
	if (buff && argv)
	{

		/*
		** check if there is a second argument
		*/

		if ((argv + 1))
		{

			/*
			** check path for ~ or -
			*/

			path = ft_path(argv[1]);
			ft_pwd(pwd);
			home = ft_get_environ("PWD");

			/*
			** check for Exiting Servers Home directory
			*/
			if (!(ft_strequ(pwd,home) == 1 && ft_strequ(path,"./..") == 1))
			{
				/*
				** attempt to chang the directory
				*/

				if (!ft_wchdir(path))
				{
					resp = ft_strdup("COMPLETE");
				}
				else
				{
					resp = ft_strdup("INCOMPLETE");
				}

				/*
				** set the buffer to be used for client response
				*/

				ft_fill_buffer(buff, resp);
			}
			else
			{
				resp = ft_strdup("ft_p: Cannot go any lower than server's Home directory");
				ft_fill_buffer(buff, resp);
			}
			/*
			** free path 
			*/

			ft_strdel(&path);
			ft_strdel(&resp);
			ft_strdel(&home);
		}
	}
	else
	{
		ft_err_quit("ft_cd fail");
	}
}