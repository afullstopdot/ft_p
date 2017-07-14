# include <ft_p.h>

int main( void )
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;

	listenfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);
	ft_set_sockaddr((SA *) &servaddr, AF_INET, SERV_PORT, htonl(INADDR_ANY));
	ft_wbind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	ft_wlisten(listenfd, BACKLOG);
	while ( 42 ) 
	{
		clilen = sizeof(cliaddr);
		connfd = ft_waccept(listenfd, (SA *) &cliaddr, &clilen);
		if ((childpid = ft_wfork()) == 0)
		{
			ft_wclose(listenfd);
			// rec req from client
			exit(0);
		}
		ft_wclose(connfd);
	}
	return (0);
}