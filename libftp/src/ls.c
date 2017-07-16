#include <libftp.h>

/*
** strjoin wrapper that expects pointer that points
** to dst must be freed
*/

static char		*ft_wstrjoin(char *dst, char *src)
{
	char 			*final;

	final = NULL;
	if (dst && src)
	{
		final = ft_strjoin(dst, src);
		ft_strdel(&dst);
	}
	return (final);
}

/*
** read contens of a directory into a newline delimetered string
*/

char		*read_dir(char *dir)
{
	DIR				*p_dir;
	struct dirent	*drnt;
	char			*dir_contents;
	char 			name[257];

	/*
	** clear str
	*/

	ft_bzero(name, 257);

	/*
	** start with empty string to append to
	*/
	
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
				** copy dirname (can never be more than 256 characters)
				*/

				ft_strcpy(name, drnt->d_name);

				/*
				** add newline to last character for displaying
				*/

				name[ft_strlen(drnt->d_name)] = '\n';
				
				/*
				** append the contents to the char * alone with a newline
				*/
				
				dir_contents = ft_wstrjoin(dir_contents, name);

				/*
				** clear string for next file/dir
				*/

				ft_bzero(name, ft_strlen(drnt->d_name) + 1);
			
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
	char			*dir_contents;
	char			*resp;

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
				** set buffer (which frees resp)
				*/

				ft_fill_buffer(buff, resp);
				ft_strdel(&dir_contents);

			}
			else
			{

				/*
				** set buffer (which frees dir_contents)
				*/
				
				ft_fill_buffer(buff, dir_contents);
				ft_strdel(&resp);
			}

		}
		else
			ft_err_quit("ft_ls fail");
	}
	else
		ft_err_quit("ft_ls fail");
}