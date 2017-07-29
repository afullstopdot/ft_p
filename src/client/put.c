# include <ft_p.h>

void           ft_send_file(int fd, t_buffer *buffer)
{
    char        *req;
    char        *res;
    char        *size;

    /*
    ** create str with cmd, filename and size by appending
    */
    if ((req = ft_strdup("put ")))
    {
        req = ft_wstrjoin(req, buffer->_filename);
        req = ft_wstrjoin(req, " ");
        if ((size = ft_itoa(buffer->_size)))
        {
            req = ft_wstrjoin(req, size);
            ft_strdel(&size);
        }
        req = ft_wstrjoin(req, "\n");
        /*
        ** send request to server
        */
        ft_send_response(req, fd);
        /*
        ** read server response into buff
        */
        if ((res = ft_wreadline(fd)))
        {
            /*
            ** if the response is OK the server is waiting for the file now
            */
            if (ft_strequ(res, "OK"))
            {
                /*
                ** free res for the next response (if the file was created server side)
                */
                ft_strdel(&res);
                /*
                ** send whole file
                */
                ft_wwriten(fd, ft_get_chunk(buffer, buffer->_size), buffer->_size); //get_chunk mem leak
                /*
                ** wait for server response of success or failue
                */
                if ((res = ft_wreadline(fd)))
                {
                    /*
                    ** dump info for user
                    */
                    if (ft_strequ(res, "OK"))
                        ft_putendl("ft_p: transfer complete");
                    else
                        ft_putendl("ft_p: transfer failed");
                }                
            }
            else if (ft_strequ(res, "KKO"))
                ft_putendl("ft_p: a file with this name exist already");
            else
                ft_putendl("ft_p: server KO'd");
        }
        
    }
}

void           ft_client_put(int fd, char **argv)
{
    t_buffer    *buffer;

    /*
    ** check that a file was specified
    */
    if ((argv[1]))
    {
        /*
        ** check that the file exists and has read rights
        */
        if (ft_file_exists(argv[1]) && fd)
        {
            /*
            ** check if a regular file
            */
            if (ft_is_regular(argv[1]))
            {
                /*
                ** read from file
                */
                if ((buffer = ft_set_buffer(argv[1])) && fd)
                {
                    /*
                    ** begin two step file transfer
                    **
                    ** step 1 - send cmd, filename and size to expect
                    ** step 2 - send entire file
                    */
                    ft_send_file(fd, buffer);
                    /*
                    ** free buffer
                    */
                    ft_free_buffer(buffer);
                }
                else
                    perror("set_buffer");
            }
            else
                ft_putendl("ft_p: invalid file type");
        }
        else
            perror("file_exist");
    }
    else
        ft_putendl("ft_p: file not specified");
}