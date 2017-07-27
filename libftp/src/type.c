#include <libftp.h>

/*
** check the file type, add yellow for regular file or blue for directory
*/

static int	get_type(char *path)
{
	struct stat	st;

	if ((lstat(path, &st)) == -1)
	{
        return (-1);
    }
	else
    {
		if (S_ISDIR(st.st_mode))
            return (1);
        else if (S_ISREG(st.st_mode))
            return (2);
    }
	return (0);
}

char		*ft_type(char *path)
{
    if (get_type(path) == 1)
        return (ft_add_color(path, BLUE));
    else if (get_type(path) == 2)
        return (ft_add_color(path, YELLOW));
    else
        return (ft_add_color(path, GREEN));
    return (ft_strdup(path));
}