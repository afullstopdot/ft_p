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
** wrapper function for accept
** NB try to call accept again if connection aborted
*/

int			ft_waccept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int		n;

	if ((n = accept(fd, sa, salenptr)) < 0) {
		ft_err_sys("accept error");
	}
	return (n);
}