# include <libftp.h>

/*
** get value of curr
*/

char			*search_environ(char *curr, char *target)
{
	char		*end;
	char		*name;
	char		*value;

	end 	= NULL;
	value 	= NULL;
	name 	= NULL;
	
	/*
	** find the pointer to the '=' delimeter
	*/

	if ((end = ft_strchr(curr, '=')))
	{

		/*
		** using the end pointer, calculate the size and create a new string
		*/
		
		if ((name = ft_strnew(end - curr)))
		{

			/*
			** copy n bytes into name
			*/
			
			ft_strncpy(name, curr, end - curr);

			/*
			** check if name is infact the target
			*/

			if (ft_strequ(name, target))
			{	
				/*
				** create new string with value prefixed by the '=' delimete
				*/

				if ((value = ft_strdup(end)))
				{
					ft_strdel(&name);
					return (value);
				}
			
			}
			ft_strdel(&name);
		}
	}
	return (value);
}

/*
** Get value of environ variable targer
*/

char			*ft_get_environ(char *target)
{
	extern char	**environ;
	char		*res;
	char		*value;
	int			count;

	count 	= 0;
	res 	= NULL;
	value 	= NULL;

	/*
	** loop through the environment
	*/

	while (environ[count])
	{

		/*
		** check for the target
		*/

		if ((res = search_environ(environ[count], target)))
		{

			/*
			** res includes '=' in the beginning. create new string 
			** without it and free
			*/

			value = ft_strdup(res + 1);

			/*
			** free res (value prefixed by '=')
			*/
			
			ft_strdel(&res);
			return (value);
		}
		count++;
	}
	ft_err_quit("environ variable not found");
	return (value);
}

/*
** change value of environ variable target
*/

void			ft_set_environ(char *target, char *value)
{
	extern char	**environ;
	char		*res;
	char		*tmp;
	int			count;

	count 	= 0;
	res 	= NULL;
	tmp 	= NULL;

	/*
	** loop through the environment
	*/

	while (environ[count])
	{

		/*
		** check for the target
		*/

		if ((res = search_environ(environ[count], target)))
		{
			tmp = ft_strjoin("=", value);
			ft_strdel(&environ[count]);
			environ[count] = ft_strjoin(target, tmp);
			ft_strdel(&res);
			ft_strdel(&tmp);
			break;
		}
		count++;
	}
}
