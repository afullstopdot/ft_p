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
				** append the contents to the char * along with a newline
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

void		ft_ls(int fd)
{
	char	*dir_contents;

	/*
	** get newline escaped string with directory contents
	*/
	if ((dir_contents = read_dir(".")))
	{
		/*
		** set buffer (which frees dir_contents)
		*/
		ft_send_response(dir_contents, fd);
		ft_strdel(&dir_contents);
	}
	else
		ft_send_response("ft_p: failed to read directory", fd);
}