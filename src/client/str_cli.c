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

void	str_cli(int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	if (ft_wreadline(0, sendline, MAXLINE))
	{
		ft_wwriten(sockfd, sendline, ft_strlen(sendline));
		if (ft_wreadline(sockfd, recvline, MAXLINE) == 0)
		{
			ft_err_quit("str_cli: server terminated prematurely");
		}
	}

}