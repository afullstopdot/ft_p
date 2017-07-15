#include <libftp.h>

int		ft_wchdir(char *path)
{
	char	*cwd;
	int		n;

	n = 0;
	cwd = ft_wgetcwd();
	if (path && cwd)
	{
		if (!(n = chdir(path)))
		{
			ft_set_environ("OLDPWD", cwd);
		}
		ft_strdel(&cwd);
	}
	return (n);
}