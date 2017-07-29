# include <ft_p.h>

/*
** Connect the client to the server
*/

int	connect_to_server(char **argv)
{
	struct sockaddr_in	servaddr;
	char				*ip_addr;
	int					sockfd;

	/*
	** resolve host IP
	*/
	ip_addr = ft_resolve_host(argv[1]);
	/*
	** open socket for tcp
	*/
	sockfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);
	/*
	** set server address
	*/
	ft_set_sockaddr((SA *) &servaddr, AF_INET, ft_atoi(argv[2]), inet_addr(ip_addr));
	/*
	** dont need resolved host IP anymore
	*/
	ft_strdel(&ip_addr);
	/*
	**  establish a connection with a TCP server
	*/
	ft_wconnect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	/*
	** return the socket fd
	*/
	return (sockfd);
}

int main(int argc, char **argv)
{
	char				*cmd;
	char 				*buff;
	int					sockfd;

	/*
	** User must specify server IP address as second argument
	*/
	if (argc != 3)
		ft_err_quit("usage: client < <IPaddress>|<DNS> > <port>");
	/*
	** connect to server
	*/
	sockfd = connect_to_server(argv);
	/*
	** we are now connected to server, display client prompt
	*/
	ft_display_prompt();
	/*
	** read from stdin
	*/
	while ((cmd = ft_wreadline(0)))
	{
		/*
		** check that command is not empty
		*/
		if (ft_strlen(cmd) > 0 && !ft_empty(cmd))
		{
			/*
			** handle local command
			*/
			if (!ft_lhandle_request(cmd, STDOUT_FILENO))
			{
				/*
				** append newline so server readline can stop correctly
				*/
				cmd = ft_wstrjoin(cmd, "\n");
				/*
				** send command to server
				*/
				ft_send_response(cmd, sockfd);
				/*
				** read server response into buff
				*/
				if ((buff = ft_wreadline(sockfd)))
				{
					/*
					** handle the command
					*/
					ft_putendl(buff);
					ft_strdel(&buff);
				}
			}
			ft_strdel(&cmd);
		}
		else
		{
			ft_strdel(&cmd);
		}
		ft_display_prompt();
	}
	return (0);
}