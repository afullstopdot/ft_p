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
<<<<<<< HEAD
				ft_send_response("ft_p: \033[0;32mlocal directory changed\n\033[0m", fd);
			}
			else
			{
				ft_send_response("ft_p: \033[0;31mfailed to change local directory\n\033[0m", fd);
=======
				ft_send_response("ft_p: local directory changed.\n", fd);
			}
			else
			{
				ft_send_response("ft_p: failed to change local directory.\n", fd);
>>>>>>> a0509b68ff7cbe70de35fe8b2efce77bcc72f016
			}
			/*
			** free path 
			*/
			ft_strdel(&path);
		}
	}
	else
	{
<<<<<<< HEAD
		ft_send_response("ft_p: \033[0;31mfailed to change local directory\n\033[0m", fd);
=======
		ft_send_response("ft_p: failed to change local directory.\n", fd);
>>>>>>> a0509b68ff7cbe70de35fe8b2efce77bcc72f016
	}
}