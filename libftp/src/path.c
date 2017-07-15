# include <libftp.h>

char	*ft_path(char *name)
{
	if (name)
	{
		if (ft_strlen(name) == 1)
		{
			if (ft_strnequ(name, "~", 1))
			{
				return (ft_get_environ("HOME"));
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
				return (ft_strjoin("./", name));
			}
		}
	}
	else 
	{
		name = ft_path("~");
	}
	return (name);
}