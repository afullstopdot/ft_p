# include <ft_p.h>

int main( void )
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
	char				*root_dir;

	listenfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);
	root_dir = NULL;
	ft_set_sockaddr((SA *) &servaddr, AF_INET, SERV_PORT, htonl(INADDR_ANY));
	ft_wbind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	ft_wlisten(listenfd, BACKLOG);
	while ( 42 ) 
	{
		clilen = sizeof(cliaddr);
		connfd = ft_waccept(listenfd, (SA *) &cliaddr, &clilen);
		if ((childpid = ft_wfork()) == 0)
		{
			root_dir = ft_wgetcwd();
			ft_wclose(listenfd);				/* close listening socket */
			ft_interpreter(connfd, root_dir);	/* process the request */
			ft_strdel(&root_dir);
			exit(0);
		}
		ft_wclose(connfd);			/* parent closes connected socket */
	}
	return (0);
}