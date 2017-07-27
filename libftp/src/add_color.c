# include <libftp.h>

/*
** add color to a string
*/

char			*ft_add_color(char *str, char *color)
{
	char		*temp;
	char		*final;

	final = NULL;
	if (str && color)
	{
		if ((temp = ft_strjoin(color, str)))
		{
			final = ft_strjoin(temp, NC);
			ft_strdel(&temp);
		}
	}
	else
		ft_err_quit("add_color fail");
	return (final);
}