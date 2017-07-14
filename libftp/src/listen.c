/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/*
** wrapper function for listen
**
** The listen function converts an unconnected socket into a passive socket, 
** indicating that the kernel should accept incoming connection requests directed 
** to this socket
*/

void		ft_wlisten(int fd, int backlog)
{
	if (listen(fd, backlog) < 0 || !backlog)
	{
		ft_err_sys("listen error");
	}
}