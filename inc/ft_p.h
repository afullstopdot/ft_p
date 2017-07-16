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

void	ft_cd(char *, char **);
void	ft_lcd(char *, char **);
void	ft_invalid(char *);
void	ft_handle_request(char *, int);
int		ft_lhandle_request(char *, int);

#endif
