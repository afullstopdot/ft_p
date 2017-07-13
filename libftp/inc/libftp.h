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

/*
** application constants
*/

# define SA 		struct sockaddr	/* generic socket address 			*/
# define SERV_PORT 	8000			/* default server port 				*/
# define BACKLOG 	15				/* default client BACKLOG 			*/
# define MAXLINE	4096			/* max text line length 			*/
# define BUFFSIZE	8192			/* buffer size for reads and writes */

#endif
