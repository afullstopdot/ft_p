/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_fatal_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/* 
** Nonfatal error related to system call
** Print message and return 
*/

void	ft_err_ret(char *fmt)
{
	printf("ft_p: non-fatal error related to system call occured - %s\n", fmt);
	return;
}

/* 
** Nonfatal error unrelated to system call
** Print message and return 
*/

void	ft_err_msg(char *fmt)
{
	printf("ft_p: non-fatal error unrelated to system call occured - %s\n", fmt);
	return;
}