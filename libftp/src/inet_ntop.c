/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inet_ntop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/*
** wrapper for inet_ntop
** Using inet_ntop instead of inet_ntoa because the goal is to write protocol
** independent code. With inet_ntop I can handle both IPv4 & IPv6
*/

const char 	*ft_winet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
	const char	*ptr;

	if (!strptr)
		ft_err_quit("NULL 3rd argument to inet_ntop");
	if (!(ptr = inet_ntop(family, addrptr, strptr, len)))
		ft_err_sys("inet_ntop error");
	return(ptr);
}