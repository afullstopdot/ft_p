# include <ft_p.h>

/*
** Change the server directory
*/

void		ft_cd(int fd, char **argv)
{
	char	*path;
	char	*home;
	char	*pwd;
	char	*final;

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
			path = ft_path(argv[1]);
			pwd = ft_wgetcwd();
			home = ft_get_environ("PWD");
			/*
			** check for Exiting Servers Home directory
			*/
			if (!(ft_strequ(pwd, home) == 1 && ft_strequ(path, "./..") == 1))
			{
				/*
				** removing spaces/newlines
				*/
				if ((final = ft_strtrim(path)))
				{
					/*
					** attempt to chang the directory
					*/
					if (!ft_wchdir(final))
						ft_send_response("ft_p: \033[0;32mdirectory changed\n\033[0m", fd);
					else
						ft_send_response("ft_p: \033[0;31mfailed to change directory\n\033[0m", fd);
				}
				else
					ft_send_response("ft_p: \033[0;31mcannot go any lower than server's HOME directory\n\033[0m", fd);
			}
			else
				ft_send_response("ft_p: \033[0;31mcannot go any lower than server's HOME directory\n\033[0m", fd);
			/*
			** free path 
			*/
			ft_strdel(&path);
			ft_strdel(&home);
			ft_strdel(&pwd);
		}
	}
	else
		ft_send_response("ft_p: \033[0;31mfailed to change directory\n\033[0m", fd);
}