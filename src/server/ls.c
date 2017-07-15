#include <ft_p.h>

/*
** append src to dst after newline is appended to src
*/

static char	*append(char *dst, char *src)
{
	char	*final;
	char	*append;

	final = NULL;
	append = NULL;
	if (dst && src)
	{

		/*
		** append newline to src
		*/
		
		if ((append = ft_strjoin(src, "\n" )))
		{

			/*
			** append newlined src to dst
			*/

			if ((final = ft_strjoin(dst, append)))
			{

				/*
				** argument dst is a malloced str that append must free
				*/
				
				ft_strdel(&dst);
			
			}

			ft_strdel(&append);
		}
	}
	return (final);
}

/*
** this function has a fuck load of memory leaks
*/

static char	*read_dir(char *dir)
{
	DIR				*p_dir;
	struct dirent	*drnt;
	char			*dir_contents;

	if ((dir_contents = ft_strdup("")))
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
				
				dir_contents = append(dir_contents, drnt->d_name);
			
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
				** fill buff with direcotory contents, 
				** using resp if newline was found
				*/

				ft_fill_buffer(buff, resp);
			}
			else
			{
				
				/*
				** fill buff with direcotory contents, 
				** using dir_con if newline was not found
				*/
				
				ft_fill_buffer(buff, dir_contents);
			
			}
			ft_strdel(&dir_contents);
			ft_strdel(&resp);
		}
		else
			ft_err_quit("ft_ls fail");
	}
	else
		ft_err_quit("ft_ls fail");
}