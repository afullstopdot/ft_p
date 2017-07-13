/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFTP_H
# define LIBFTP_H

# include <libft.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>

/*
** application constants
*/

# define SA 		struct sockaddr	/* generic socket address 			*/
# define SERV_PORT 	8000			/* default server port 				*/
# define BACKLOG 	15				/* default client BACKLOG 			*/
# define MAXLINE	4096			/* max text line length 			*/
# define BUFFSIZE	8192			/* buffer size for reads and writes */

/*
** Read / Write to a socket
*/

ssize_t			ft_readn(int, void *, size_t);			/* read n bytes of fd into buffer */
ssize_t			ft_writen(int, const void *, size_t);	/* write "n" bytes to a fd */
void			ft_display_prompt(void);

/*
** wrapper functions
*/

ssize_t			ft_wreadn(int, void *, size_t);
ssize_t			ft_wreadline(int, void *, size_t);
void			ft_wwriten(int, void *, size_t);
void			ft_wbind(int, const struct sockaddr *, socklen_t);
void			ft_wlisten(int, int);
void			ft_wclose(int);
void			ft_wconnect(int, const struct sockaddr *, socklen_t);
void			ft_set_sockaddr(struct sockaddr *, int, int, in_addr_t);
int				ft_wsocket(int, int, int);
int				ft_waccept(int, struct sockaddr *, socklen_t *);
pid_t			ft_wfork(void);
char			*ft_wgetcwd(void);

/*
** Error handling
*/

void			ft_err_ret(char *);		/* Nonfatal error related to system call */
void			ft_err_msg(char *);		/* Nonfatal error unrelated to system call */
void			ft_err_sys(char *);		/* Fatal error related to system call */
void			ft_err_quit(char *);	/* Fatal error unrelated to system call */

#endif