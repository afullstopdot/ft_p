/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inet_pton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/*
** wrapper function for inet_pton
*/

void	ft_winet_pton(int family, const char *strptr, void *addrptr)
{
	int		n;

	if ((n = inet_pton(family, strptr, addrptr)) < 0)
		ft_err_sys("inet_pton error");	/* errno set */
	else if (n == 0)
		ft_err_quit("inet_pton error");	/* errno not set */
}