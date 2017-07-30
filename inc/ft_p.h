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
** On MacOS extern char **environ must not be free'd
*/

#ifdef __APPLE__
# define FREE_ENVIRON FALSE
#else
# define FREE_ENVIRON TRUE
#endif

/*
** server
*/

void    ft_server_put(int fd, char **argv);
void    ft_server_get(int fd, char **argv);
void	ft_cd(int fd, char **pptr);
void	ft_invalid(int fd);
void	ft_handle_request(char *line, int fd);

/*
** client
*/

void    ft_client_put(int fd, char **argv);
void    ft_client_get(int fd, char **argv);
void	ft_lcd(int fd, char **pptr);
int		ft_lhandle_request(char *line, int fd);
int		ft_handle_special(char *line, int connfd);

#endif