/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <libftp.h>

/*
** On MacOS environ must not be free'd
*/

#ifdef __APPLE__
# define FREE_ENVIRON FALSE
#else
# define FREE_ENVIRON TRUE
#endif


void	ft_cd(char *ptr, char **pptr);
void	ft_lcd(char *ptr, char **pptr);
void	ft_invalid(char *ptr);
void	ft_handle_request(char *ptr, int arg);
int		ft_lhandle_request(char *ptr, int arg);

#endif