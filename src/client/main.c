# include <ft_p.h>

/*
** Take note, right now. The client are using the constant SERV_PORT
** this must be changed as per PDF 
*/

int main(int argc, char **argv)
{
	char				*cmd;
	char 				buff[MAXLINE];
	int					sockfd;
	struct sockaddr_in	servaddr;

	/*
	** User must specify server IP address as second argument
	*/

	if (argc != 3)
		ft_err_quit("usage: client <IPaddress> <port>");

	/*
	** open socket for tcp
	*/

	sockfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);

	/*
	** set server address
	*/

	ft_set_sockaddr((SA *) &servaddr, AF_INET, ft_atoi(argv[2]), inet_addr(argv[1]));

	/*
	**  establish a connection with a TCP server
	*/

	ft_wconnect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	/*
	** display client prompt
	*/
	
	ft_display_prompt();

	/*
	** read from stdin
	*/

	while ((cmd = ft_wreadline()))
	{

		if (ft_strlen(cmd) > 0 && !ft_empty(cmd))
		{

			/*
			** set buff with cmd contents, free cmd for next read
			*/

			ft_fill_buffer(buff, cmd);

			/*
			** handle local command
			*/

			if (!ft_lhandle_request(buff, STDOUT_FILENO))
			{

				/*
				** write buff to server socket
				*/

				ft_wwriten(sockfd, buff, MAXLINE);

				/*
				** clean buff
				*/

				ft_bzero(buff, MAXLINE);

				/*
				** read server response into buff
				*/

				if (ft_wreadn(sockfd, buff, MAXLINE))
				{
					ft_putstr(buff);
					ft_putstr("\n");
				}
			
			}

		}
		else
		{
			ft_strdel(&cmd);
		}
		ft_display_prompt();
	}
	return (0);
}