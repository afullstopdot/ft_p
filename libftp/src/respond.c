# include <libftp.h>

/*
** write to fd
*/

void		ft_send_response(char *buff, int connfd)
{
	if (buff)
	{
		ft_wwriten(connfd, buff, ft_strlen(buff));
	}
	else
	{
		ft_err_quit("ft_send_response fail");
	}
}