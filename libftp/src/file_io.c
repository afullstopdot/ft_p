#include <libftp.h>

/*
** get the file size
*/

size_t	        ft_file_size(int fd)
{
	struct stat st;

	if ((fstat(fd, &st)) == -1)
		return (FALSE);
	return (st.st_size);
}

/*
** check that file is regular
*/

int	            ft_is_regular(char *path)
{
	struct stat	st;

	if ((lstat(path, &st)) == -1)
	{
        return (-1);
    }
    return (S_ISREG(st.st_mode));
}

/*
** check if a file exists
*/

int             ft_file_exists(char *file)
{
    struct stat st;
    int			fd;

    /*
    ** get file descriptor
    */
    if ((fd = open(ft_strtrim(file), O_RDONLY)) == -1)
	{
		return (FALSE);
	}
    /*
    ** fstat file
    */
	if ((fstat(fd, &st)) == -1)
	{
        close(fd);
        return (FALSE);
    }
    close(fd);
	return (TRUE);
}