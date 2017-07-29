/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftp.h>

/*
** Read a void pointer, from buffer offset upto size bytes
*/

void 	*ft_get_chunk(t_buffer *buffer, size_t size)
{

	void	*chunk;

	chunk = NULL;	
	if (buffer)
	{
		if ((buffer->_offset + size) > buffer->_size)
			return (NULL);
		if ((chunk = ft_memalloc(size)))
		{
			chunk = ft_memcpy(chunk, (void *)((char *)buffer->_stream + buffer->_offset), size);
			if (!chunk)
				return (NULL);
			buffer->_offset += size;
		}
	}
	return ( chunk );

}

/*
** Delete malloced chunk
*/

void	ft_free_chunk(void *chunk)
{
	if (chunk)
		ft_memdel(&chunk);
}