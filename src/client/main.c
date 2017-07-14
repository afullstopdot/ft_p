# include <ft_p.h>

int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		ft_err_quit("usage: client <IPaddress>");
	sockfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);
	ft_set_sockaddr((SA *) &servaddr, AF_INET, SERV_PORT, inet_addr(argv[1]));
	ft_wconnect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	while (1) 
	{
		ft_display_prompt();
		// send req to server
	}
	exit(0);
}