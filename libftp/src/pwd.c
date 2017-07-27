# include <libftp.h>

/*
** get cwd and send response to client
*/

void		ft_pwd(int fd)
{
	char	*cwd;

	cwd = NULL;
	if ((cwd = ft_wgetcwd()))
	{
		ft_send_response(cwd, fd);
		ft_strdel(&cwd);
	}
	else
	{
		ft_send_response("ft_p: an error occured for pwd command", fd);
	}
}