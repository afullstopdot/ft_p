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
			return (-1);
		}
		else if (nread == 0)
			break;				/* EOF */
		nleft -= nread;
		ptr   += nread;
	}
	return (n - nleft);			/* return >= 0 */
}

ssize_t			ft_wreadn(int fd, void *ptr, size_t nbytes)
{
	ssize_t		n;

	if ((n = ft_readn(fd, ptr, nbytes)) < 0)
	{
		ft_err_sys("readn error");
	}
	return (n);
}