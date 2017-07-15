#include <ft_p.h>

// this function has a fuck load of memory leaks

char		*read_dir(char *dir)
{
	DIR				*p_dir;
	struct dirent	*drnt;
	char			*dir_contents;

	if ((dir_contents = ft_strnew(1)))
	{

		/*
		** open the directory for reading
		*/

		if ((p_dir = opendir(dir)))
		{

			/*
			** read the directory contents
			*/

			while ((drnt = readdir(p_dir)) != NULL)
			{
				
				/*
				** append the contents to the char * alone with a newline
				*/
				
				dir_contents = ft_strjoin( dir_contents, ft_strjoin( drnt->d_name, "\n" ) );
			
			}

			/*
			** close the open directory
			*/

			closedir(p_dir);
		}
	}
	return (dir_contents);
}

/*
** Simple ls
*/

void		ft_ls(char *buff)
{
	char	*dir_contents;
	char	*resp;

	dir_contents = NULL;
	if (buff)
	{

		/*
		** get newline escaped string with directory contents
		*/

		dir_contents = read_dir(".");
		if (dir_contents)
		{

			/*
			** try to to trim last newline from read_dir()
			*/
			
			if ((resp = ft_strtrim(dir_contents))) 
			{

				/*
				** fill buff with direcotory contents
				*/

				ft_fill_buffer(buff, resp);
				ft_strdel(&dir_contents);
			}
			else
				ft_fill_buffer(buff, dir_contents);
		}
		else
			ft_err_quit("ft_ls fail");
	}
	else
		ft_err_quit("ft_ls fail");
}