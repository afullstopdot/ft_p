/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

void		ft_pwd(int sockfd)
{
	char	*cwd;

	if ((cwd = ft_wgetcwd()))
	{
		ft_wwriten(sockfd, cwd, sizeof(cwd));
		ft_strdel(&cwd);
	}
	else
	{
		ft_err_quit("ft_wgetcwd fail");
	}
}