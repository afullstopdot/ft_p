/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/*
** Read "n" bytes from a descriptor into "vptr"
*/

ssize_t	ft_readn(int fd, void *vptr, size_t n)
{
	size_t		nleft;
	ssize_t		nread;
	char		*ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0)
	{
		if ((nread = read(fd, ptr, nleft)) < 0)
		{
			if (errno == EINTR)
				nread = 0;		/* and call read() again */
			else
				return (-1);
		}
		else if (nread == 0)
			break;				/* EOF */
		nleft -= nread;
		ptr   += nread;
	}
	return (n - nleft);			/* return >= 0 */
}

/*
** ft_readn wrapper function
** If the system supports the MSG_WAITALL flag we can omit the ft_readn 
** function which keeps calling to read until n bytes are read and use 
** recv rather. It tells the kernel not to return from a read operation 
** until the requested number of bytes have been read. 
*/

ssize_t			ft_wreadn(int fd, void *ptr, size_t nbytes)
{
	ssize_t		n;

#ifndef MSG_WAITALL
	if ((n = ft_readn(fd, ptr, nbytes)) < 0) {
		ft_err_sys("readn error");
	}
#else
	if ((n = recv(fd, ptr, nbytes, MSG_WAITALL)) < 0) {
		ft_err_sys("readn error");
	}
#endif
	return (n);
}