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

void	ft_display_prompt(void)
{
	char	cwd[255];

	if (getcwd(cwd, 255))
	{
		ft_putstr("\033[0;35m(\033[0m\033[0;40mLOCAL\033[0m\033[0;35m");
		ft_putstr(cwd);
		ft_putstr(")$ \033[0m");
	}
	else
		ft_err_quit("getcwd fail");
}