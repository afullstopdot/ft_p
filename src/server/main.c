# include <ft_p.h>

int main(void)
{
	int					listenfd;
	int 				connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
	char				buff[MAXLINE];
	char				**argv;

	/*
	** create a socket
	*/

	listenfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);

	/*
	** set socket address
	** NB - INADDR_ANY tells the kernel to accept requests 
	** on any interface for port `SERV_PORTS`
	*/

	ft_set_sockaddr((SA *) &servaddr, AF_INET, SERV_PORT, htonl(INADDR_ANY));

	/*
	** assign a local protocol address to a socket
	*/

	ft_wbind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	/*
	** convert unconnected socket into a passive socket 
	** (accept incoming connection requests directed to this socket)
	*/

	ft_wlisten(listenfd, BACKLOG);
	while ( 42 ) 
	{
		clilen = sizeof(cliaddr);

		/*
		** return next completed connection (client request accepted) from the 
		** que, assign the file descriptor to connfd
		*/

		connfd = ft_waccept(listenfd, (SA *) &cliaddr, &clilen);

		/*
		** fork a new process, so we can handle multiple clients
		*/

		if ((childpid = ft_wfork()) == 0)
		{
			ft_wclose(listenfd);
			while (ft_wreadn(connfd, buff, MAXLINE)) {
				if ((argv = ft_strsplit(buff, ' '))) {
					if (ft_strequ(argv[0], "pwd")) {
						ft_bzero(buff, MAXLINE);
						ft_strcpy(buff, ft_wgetcwd());
						ft_wwriten(connfd, buff, MAXLINE);
					}
				}
			}
			exit(0);
		}
		ft_wclose(connfd);
	}
	return (0);
}