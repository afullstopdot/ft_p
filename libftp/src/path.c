# include <libftp.h>

char	*ft_path(char *name)
{
	if (name)
	{
		if (ft_strlen(name) == 1)
		{
			if (ft_strequ(name, "~"))
			{
				return (ft_get_environ("PWD"));
			}
			else if (ft_strnequ(name, "-", 1))
			{
				return (ft_get_environ("OLDPWD"));
			}
		}
		else
		{
			if (!ft_strchr(name, '/'))
			{
				return (ft_path(ft_strjoin("./", name)));
			}
			else if (ft_strnequ(name, "~/", 1) == 1)
			{
				return (ft_strjoin(ft_get_environ("PWD"),name + 1));
			}
		}
	}
	else 
	{
		name = ft_path("~");
	}
	return (name);
}