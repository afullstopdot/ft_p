# include <libftp.h>

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
					return (value);
				}
			
			}
		}
	}
	return (value);
}

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
		** check for the = delimeter
		*/

		if ((res = search_environ(environ[count], target)))
		{

			/*
			** res includes '=' in the beginning. create new string 
			** without it and free
			*/

			value = ft_strdup(res + 1);
			ft_strdel(&res);
			return (value);
		}
		count++;
	}
	ft_err_quit("environ variable not found");
	return (value);
}