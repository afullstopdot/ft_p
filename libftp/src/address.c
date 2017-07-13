/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/*
** Fill socket address
*/

void	ft_set_sockaddr(struct sockaddr *sa, int family, int port, in_addr_t address)
{
	struct sockaddr_in	*servaddr;

	servaddr = (struct sockaddr_in*)sa;
	if (servaddr)
	{
		ft_bzero(servaddr, sizeof(servaddr));
		servaddr->sin_family = family;
		servaddr->sin_port = htons(port);
		servaddr->sin_addr.s_addr = address;
	}
	else
	{
		ft_err_quit("ft_fill_address fail");
	}
}