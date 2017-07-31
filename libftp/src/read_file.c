#include <libftp.h>

static char		*get_filename(char *path)
{
	if (ft_strchr(path, '/'))
	{
		return (ft_strdup(ft_strrchr(path, '/') + 1));
	}
	return (ft_strdup(path));
}

/*
** populate buffer info
*/

static t_buffer	*get_binary_bytes(int fd, size_t size)
{

	t_buffer	*buffer;
	void 		*mapped;

	buffer = NULL;
	mapped = mmap(0, size, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
	if (mapped == MAP_FAILED)
	{
		fprintf(stderr, "ERROR: Mapping of file failed: ");
		fprintf(stderr, "%d - %s\n", errno, strerror(errno));
		return (NULL);

	}

	if (!(buffer = (t_buffer*)malloc(sizeof(t_buffer))))
	{
		fprintf(stderr, "ERROR: Malloc of t_list failed: ");
		fprintf(stderr, "%d - %s\n", errno, strerror(errno));
		return (NULL);

	}
	buffer->_stream = mapped;
	buffer->_filename = NULL;
	buffer->_size 	= size;
	buffer->_offset = 0;


	return (buffer);

}

/*
** free buffer
*/

void			ft_free_buffer(t_buffer *buffer)
{

	if (buffer)
	{
		munmap(buffer->_stream, buffer->_size);
		free(buffer);
	}

}

/*
** read a binary file and init buffer
*/

t_buffer 		*ft_set_buffer(char *path)
{

	t_buffer	*buffer;
	size_t		file_size;
	int			fd;

	buffer = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		perror("set_buffer");
		return (NULL);

	}
	if ((file_size = ft_file_size(fd)) != 0)
	{
		/*
		** get byte stream and set buffer
		*/
		buffer = get_binary_bytes(fd, file_size);
		/*
		** get filename and set in buffer
		*/
		buffer->_filename = get_filename(path);
	}
	close(fd);
    return (buffer);
}