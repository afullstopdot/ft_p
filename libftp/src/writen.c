/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rwriten.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/*
** Write "n" bytes to a descriptor.
*/

ssize_t			ft_writen(int fd, const void *vptr, size_t n)
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0) 
	{
		if ((nwritten = write(fd, ptr, nleft)) <= 0) 
		{
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;	/* and call write() again */
			else
				return (-1);	/* error */
		}
		nleft -= nwritten;
		ptr   += nwritten;
	}
	return (n);
}

void			ft_wwriten(int fd, void *ptr, size_t nbytes)
{
	if (ft_writen(fd, ptr, nbytes) != (ssize_t)nbytes) {
		ft_err_sys("writen error");
	}
}