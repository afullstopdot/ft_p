# include <ft_p.h>

/*
** Change the server directory
*/

void		ft_lcd(char *buff, char **argv)
{
	char	*resp;
	char	*path;

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

			path = ft_lpath(argv[1]);
			printf("%s\n", path);
			/*
			** attempt to chang the directory
			*/

			if (!ft_wchdir(path))
			{
				resp = ft_strdup("LCOMPLETE");
			}
			else
			{
				resp = ft_strdup("LINCOMPLETE");
			}

			/*
			** set the buffer to be used for client response
			*/

			ft_fill_buffer(buff, resp);

			/*
			** free path 
			*/

			ft_strdel(&path);
		}
	}
	else
	{
		ft_err_quit("ft_cd fail");
	}
}