# include <libftp.h>

/*
** Get value of environ variable targer
*/

static char		**create_environ(void)
{
	char		**envp;
	char		*value;

	envp = NULL;
	value = NULL;
	if ((envp = ft_memalloc(sizeof(char *) + 4)))
	{
		if ((value = ft_get_environ("PWD")))
		{
			envp[0] = ft_strjoin("PWD=", value);
			ft_strdel(&value);
		}
		if ((value = ft_get_environ("OLDPWD")))
		{
			envp[1] = ft_strjoin("OLDPWD=", value);
			ft_strdel(&value);
		}
		if ((value = ft_get_environ("HOME")))
		{
			envp[2] = ft_strjoin("HOME=", value);
			ft_strdel(&value);
		}
		envp[3] = NULL;
	}
	return (envp);
}

void			ft_free_environ(void)
{
	extern char	**environ;
	int 		count;

	count = 0;
	while (environ[count])
	{
		ft_strdel(&environ[count++]);
	}
	free(environ);
}

/*
** change value of environ variable target
*/

void			ft_init_environ(void)
{
	extern char	**environ;

	if (!(environ = create_environ()))
	{
		ft_err_quit("init_environ fail");
	}
}