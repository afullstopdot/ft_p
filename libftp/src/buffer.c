/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:34:08 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/14 18:34:31 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

void	ft_fill_buffer(char *buff, char *line)
{
	if (buff && line)
	{
		ft_strcpy(buff, line);
		ft_strdel(&line);
	}
	else
	{
		ft_err_quit("ft_fill_buffer error");
	}
}