# include <ft_p.h>

int main(int argc, char **argv)
{
	char				*cmd;
	char 				buff[MAXLINE];
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		ft_err_quit("usage: client <IPaddress>");
	sockfd = ft_wsocket(AF_INET, SOCK_STREAM, 0);
	ft_set_sockaddr((SA *) &servaddr, AF_INET, SERV_PORT, inet_addr(argv[1]));
	ft_wconnect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	ft_display_prompt();
	while ((cmd = ft_wreadline()))
	{
		ft_strcpy(buff, cmd);
		ft_strdel(&cmd);
		ft_wwriten(sockfd, buff, MAXLINE);
		ft_bzero(buff, MAXLINE);
		if (ft_wreadn(sockfd, buff, MAXLINE)) {
			ft_putstr(buff);
			ft_putstr("\n");
		}
		ft_display_prompt();
	}
	return (0);
}