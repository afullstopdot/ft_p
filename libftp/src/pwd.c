# include <libftp.h>

/*
** get cwd and send response to client
*/

void		ft_pwd(int fd)
{
	char	*final;
	char	*cwd;

	cwd = NULL;
	if ((cwd = ft_wgetcwd()))
	{
		if ((final = ft_add_color(cwd, YELLOW)))
		{
			ft_send_response(final, fd);
			ft_strdel(&final);
		}
		else
			ft_send_response(cwd, fd);
		ft_strdel(&cwd);
	}
	else
	{
		ft_send_response("ft_p: an error occured for pwd command", fd);
	}
}