# include <libftp.h>

void		ft_invalid(int fd)
{
	ft_send_response("ft_p: command not supported", fd);
}