# include <ft_p.h>

void		ft_pwd(char *buff)
{
	char	*cwd;

	cwd = NULL;
	if (buff && (cwd = ft_wgetcwd()))
	{
		ft_strcpy(buff, cwd);
		ft_strdel(&cwd);
	}
	else
	{
		ft_err_quit("ft_pwd fail");
	}
}