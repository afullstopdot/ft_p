# include <ft_p.h>

int main(int argc, char **argv)
{
	int					listenfd;
	int 				connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
	char				*buff;

	if (argc != 2)
		ft_err_msg("ft_p: usage server <PORT>");
	/*
	** create a socket
	*/
	listenfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);
	/*
	** set socket address
	** NB - INADDR_ANY tells the kernel to accept requests 
	** on any interface for port `SERV_PORTS`
	*/
	ft_set_sockaddr((SA *) &servaddr, AF_INET, ft_atoi(argv[1]), htonl(INADDR_ANY));
	/*
	** assign a local protocol address to a socket
	*/
	ft_wbind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	/*
	** convert unconnected socket into a passive socket 
	** (accept incoming connection requests directed to this socket)
	*/
	ft_wlisten(listenfd, BACKLOG);
	/*
	** handle connections
	*/
	while (42) 
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
			/*
			** initialize environment with variables we want
			*/
			ft_init_environ();
			/*
			** close to prevent zombies
			*/
			ft_wclose(listenfd);
			/*
			** read from client as long as client is writing
			*/
			while ((buff = ft_wreadline(connfd)))
			{
				/*
				** break from loop, close connection
				*/
				if (ft_strequ(buff, "quit"))
				{
					ft_strdel(&buff);
					ft_send_response("\033[0;31mbye.\033[0m", connfd);
					break;
				}
				/*
				** handle the command
				*/
				ft_handle_request(buff, connfd);
				ft_strdel(&buff);
			}
			/*
			** kill the process
			*/
			exit(0);
		}
		/*
		** close connection
		*/
		ft_wclose(connfd);
	}
	return (0);
}


// it would appear the compile does not like it when you free a ptr you are assigning to wtf