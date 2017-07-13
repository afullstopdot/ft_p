/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/* 
** Fatal error related to system call
** Print message and terminate 
*/

void			ft_err_sys(char* fmt)
{
	printf("ft_p: fatal error related to system call occured - %s\n", fmt);
	exit(1);
}

/* 
** Fatal error unrelated to system call
** Print message and terminate 
*/

void			ft_err_quit(char* fmt)
{
	printf("ft_p: fatal error unrelated to system call occured - %s\n", fmt);
	exit(1);
}