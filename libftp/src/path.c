# include <libftp.h>

char	*ft_path(char *name)
{
	char	*home;
	char	*joined;

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
			else if (ft_strequ(name, "/"))
			{
				return (ft_get_environ("PWD"));
			}
			else
			{
				return (ft_strdup(name));
			}
		}
		else
		{
			if (!ft_strchr(name, '/'))
			{
				return (ft_path(ft_strjoin("./", name)));
			}
			else if (ft_strnequ(name, "~/", 1))
			{
				home = ft_get_environ("PWD");
				joined = ft_strjoin(home,name + 1);
				ft_strdel(&home);
				return (joined);
			}
			else if (ft_strnequ(name, "/", 0))
			{
				home = ft_get_environ("PWD");
				joined = ft_strjoin(home,name);
				ft_strdel(&home);
				return (joined);
			}
			else if (!(ft_strequ(name,"./..") == 1) && !(ft_strnequ(name,"./",1) == 1))
			{
				home = ft_get_environ("PWD");
				joined = ft_strjoin(home,"/");
				ft_strdel(&home);
				home = ft_strjoin(joined,name);
				ft_strdel(&joined);
				return (home);
			}
		}
	}
	else 
	{
		name = ft_path("~");
	}
	return (name);
}

char	*ft_lpath(char *name)
{
	char	*home;
	char	*joined;

	if (name)
	{
		if (ft_strlen(name) == 1)
		{
			if (ft_strequ(name, "~"))
			{
				return (ft_get_environ("HOME"));
			}
			else if (ft_strnequ(name, "-", 1))
			{
				return (ft_get_environ("OLDPWD"));
			}
			else if (ft_strequ(name, "/"))
			{
				return (ft_get_environ("HOME"));
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
				home = ft_get_environ("HOME");
				joined = ft_strjoin(home,name + 1);
				ft_strdel(&home);
				return (joined);
			}
			else if (ft_strnequ(name, "/", 0) == 1)
			{
				home = ft_get_environ("HOME");
				joined = ft_strjoin(home,name);
				ft_strdel(&home);
				return (joined);
			}
			else if (!(ft_strequ(name,"./..") == 1) && !(ft_strnequ(name,"./",1) == 1))
			{
				home = ft_get_environ("PWD");
				joined = ft_strjoin(home,"/");
				ft_strdel(&home);
				home = ft_strjoin(joined,name);
				ft_strdel(&joined);
				return (home);
			}
		}
	}
	else 
	{
		name = ft_lpath("~");
	}
	return (name);
}