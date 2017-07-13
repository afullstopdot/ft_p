/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

static void	ft_set_buf(int sockfd, char *buf)
{
	if (ft_wreadline(sockfd, buf, MAXLINE) == 0)
	{
		ft_err_quit("str_cli: server terminated prematurely");
	}
}

void		ft_interpreter(int sockfd, char *root_dir)
{
	char		**argv;
	char		buf[MAXLINE];
	int 		count;

	ft_set_buf(sockfd, buf);
	argv = NULL;
	count = 0;
	if ((argv = ft_strsplit(buf, ' ')) && root_dir)
	{
		while (argv[count])
		{
			printf("%s\n", argv[count]);
			// if (ft_strequ(argv[count], "pwd"))
			// {
			// 	ft_putstr("pwd asked for");
			// 	// ft_pwd(sockfd);
			// 	break;
			// }
			count++;
		}
	}
	else
	{
		ft_err_quit("ft_strsplit fail");
	}
}