# include <ft_p.h>

/*
** Change the server directory
*/

void		ft_cd(char *buff, char *root_dir, char **argv)
{
	char	*resp;
	char	*path;

	resp = NULL;
	path = NULL;
	if (buff && root_dir && argv)
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
	}
	else
	{
		ft_err_quit("ft_cd fail");
	}
}