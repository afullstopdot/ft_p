# include <ft_p.h>

void           ft_server_get(int connfd, char **argv)
{
    // int        fd;
    t_buffer   *buffer;
    char       *req;
    char       *res;

    if (argv[1])
    {
        /*
        ** check if the file requested exists on the server
        */
        if (ft_file_exists(argv[1]))
        {
            if ((buffer = ft_set_buffer(argv[1])))
            {
                req = ft_strjoin("OK ", buffer->_filename);
                req = ft_wstrjoin(req, " ");
                req = ft_wstrjoin(req, ft_itoa(buffer->_size)); //mem leak here
                req = ft_wstrjoin(req, "\n");
                /*
                ** send response (success and filename)
                */
                ft_send_response(req, connfd);
                /*
                ** read from client res on whether to continue
                */
                if ((res = ft_wreadline(connfd)))
                {
                    /*
                    ** client is waiting for bytes
                    */
                    if (ft_strequ(res, "OK"))
                    {
                        /*
                        ** send all bytes
                        */
                        ft_wwriten(connfd, ft_get_chunk(buffer, buffer->_size), buffer->_size);
                    }
                }
            }
            else
                ft_send_response("KKKO\n", connfd);
        }
        else
        {
            ft_send_response("KO\n", connfd);
        }
    }
    else
    {
        ft_send_response("KKO\n", connfd);
    }
}