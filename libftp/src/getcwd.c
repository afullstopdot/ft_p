/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

char		*ft_wgetcwd(void)
{
	char	*final;
	char	cwd[255];

	if (getcwd(cwd, 255))
	{
		if ((final = ft_strnew(ft_strlen(cwd) + 1)))
		{
			ft_strcpy(final, cwd);
			final[ft_strlen(cwd)] = '\n'; 
			final[ft_strlen(cwd) + 1] = '\0'; 
			return (final);
		}
		return (ft_strdup(cwd));
	}
	else
		ft_err_quit("getcwd fail");
	return (NULL);
}