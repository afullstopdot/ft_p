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
# include <sys/mman.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>

/*
** file buff
*/

typedef struct	s_buffer
{
	void		*_stream;
	char		*_filename;
	size_t		_size;
	size_t		_offset;

}				t_buffer;

/*
** application constants
*/

# define SA 		struct sockaddr	/* generic socket address 			*/
# define SERV_PORT 	8000			/* default server port 				*/
# define BACKLOG 	15				/* default client BACKLOG 			*/
# define MAXLINE	4096			/* max text line length 			*/
# define RED        "\033[0;31m"
# define YELLOW     "\033[0;33m"
# define GREEN      "\033[0;32m"
# define BLUE       "\033[0;34m"
# define NC         "\033[0m"

/*
** Read / Write to a fd
*/

ssize_t			ft_readn(int, void *, size_t);
ssize_t			ft_writen(int, const void *, size_t);
ssize_t			ft_wreadn(int, void *, size_t);
char			*ft_wreadline(int);
void			ft_wwriten(int, void *, size_t);

/*
** socket wrapper functions
*/


void			ft_wbind(int, const struct sockaddr *, socklen_t);
void			ft_wlisten(int, int);
void			ft_wclose(int);
void			ft_wconnect(int, const struct sockaddr *, socklen_t);
void			ft_set_sockaddr(struct sockaddr *, int, int, in_addr_t);
int				ft_wsocket(int, int, int);
int				ft_waccept(int, struct sockaddr *, socklen_t *);

/*
** server environment handlers
*/

void			ft_init_environ(void);
void			ft_free_environ(void);
void			ft_set_environ(char *, char *);
char			*ft_get_environ(char *);

/*
** server multiple processes
*/

pid_t			ft_wfork(void);

/*
** server/client built in commands
*/

void			ft_ls(int fd);
void			ft_pwd(int fd);

/*
** server/client path handlers
*/

char			*ft_path(char *);
char			*ft_lpath(char *name);

/*
** server/client command interpreter
*/

char			**ft_get_argv(char *);

/*
** server/client socket writing
*/

void		    ft_send_response(char *buff, int connfd);

/*
** client prompt
*/

void			ft_display_prompt(void);

/*
** file I/O
*/

char		    *ft_type(char *path);
int             ft_file_exists(char *file);
int	            ft_is_regular(char *path);
size_t	        ft_file_size(int fd);
void 	        *ft_get_chunk(t_buffer *buffer, size_t size);
t_buffer 		*ft_set_buffer(char *path);
void			ft_free_buffer(t_buffer *buffer);
void	        ft_free_chunk(void *chunk);


/*
** helper functions
*/

void			ft_fill_buffer(char *, char *);
void			ft_check_exit(char *);
void			ft_dstrdel(char **);
int				ft_dstrlen(char **);
int				ft_empty(char *);
char			*ft_add_color(char *str, char *color);
char		    *ft_wstrjoin(char *dst, char *src);

/*
** server/client built in command wrapper functions
*/

int				ft_wchdir(char *);
char			*ft_wgetcwd(void);

/*
** Host names
*/

char            *ft_resolve_host(char *argv);

/*
** Error handling
*/

void			ft_err_ret(char *);		/* Nonfatal error related to system call */
void			ft_err_msg(char *);		/* Nonfatal error unrelated to system call */
void			ft_err_sys(char *);		/* Fatal error related to system call */
void			ft_err_quit(char *);	/* Fatal error unrelated to system call */

#endif