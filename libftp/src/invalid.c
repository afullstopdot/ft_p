# include <libftp.h>

void		ft_invalid(char *buff)
{
	char	*defaults;

	defaults = NULL;
	if (buff && (defaults = ft_strdup("ft_p: command not supported")))
	{
		ft_strcpy(buff, defaults);
		ft_strdel(&defaults);
	}
	else
	{
		ft_err_quit("ft_pwd fail");
	}
}