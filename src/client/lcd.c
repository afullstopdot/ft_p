# include <ft_p.h>

/*
** Change the server directory
*/

void		ft_lcd(int fd, char **argv)
{
	char	*path;

	if (argv)
	{
		/*
		** check if there is a second argument
		*/
		if ((argv + 1))
		{
			/*
			** check path for ~ or -
			*/
			path = ft_lpath(argv[1]);
			/*
			** attempt to chang the directory
			*/
			if (!ft_wchdir(path))
			{
				ft_send_response("ft_p: local directory changed.\n", fd);
			}
			else
			{
				ft_send_response("ft_p: failed to change local directory.\n", fd);
			}
			/*
			** free path 
			*/
			ft_strdel(&path);
		}
	}
	else
	{
		ft_send_response("ft_p: failed to change local directory.\n", fd);
	}
}