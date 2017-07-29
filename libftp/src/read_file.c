#include <libftp.h>

/*
** get the file size for mmap call
*/

static size_t	get_file_size( int fd )
{
	struct stat st;
	int 		res;

	if ((fstat(fd, &st)) == -1)
		return (FALSE);
	return (st.st_size);
}

/*
** populate buffer info
*/

static t_buffer	*get_binary_bytes( int fd, size_t size )
{

	t_buffer	*buffer;
	void 		*mapped;

	buffer = NULL;
	mapped = mmap( 0, size, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0 );

	if ( mapped == MAP_FAILED ) {

		// for debugging
		fprintf( stderr, "ERROR: Mapping of file failed: ");
		fprintf( stderr, "%d - %s\n", errno, strerror( errno ) );

		return ( NULL );

	}

	buffer = ( t_buffer* )malloc( sizeof( t_buffer ) );
	if ( !buffer ) {

		// for debugging
		fprintf( stderr, "ERROR: Malloc of t_list failed: ");
		fprintf( stderr, "%d - %s\n", errno, strerror( errno ) );
		return ( NULL );

	}

	buffer->_stream = mapped;
	buffer->_size 	= size;
	buffer->_offset = __MAGIC_OFFSET__;


	return ( buffer );

}

/*
** free buffer
*/

void			_free_buffer( t_buffer *buffer )
{

	if ( buffer ) {

		munmap( buffer->_stream, buffer->_size );
		free( buffer );

	}

}

/*
** read a binary file and init buffer
*/

t_buffer 		*_set_buffer( char *path )
{

	t_buffer	*buffer;
	size_t		file_size;
	int			fd;

	fd 		= open( path, O_RDWR );
	if ( fd <  0 ) {

		// for debugging
		fprintf( stderr, "ERROR: Opening of %s failed: ", path );
		fprintf( stderr, "%d - %s\n", errno, strerror( errno ) );
		return ( NULL );

	}

	file_size = get_file_size( fd );

	if ( file_size ) {

		buffer = get_binary_bytes( fd, file_size );
	
	}

	close( fd );
    return ( buffer );

}