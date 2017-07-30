# include <ft_p.h>

static int     ft_wfile_exists(char *res)
{
    char       **argv;

    if ((argv = ft_get_argv(res)))
    {
        if (argv[1])
        {
            return (ft_file_exists(argv[1]));
        }
    }
    return (TRUE);
}

void           ft_save_file(int fd, char *res)
{
    char       **argv;
    char       *buff;
    int        local_fd;

    if ((argv = ft_get_argv(res)))
    {
        if (argv[1] && argv[2])
        {
            if ((buff = ft_strnew(ft_atoi(argv[2]))))
            {
                /*
                ** read file contents
                */
                ft_wreadn(fd, buff, ft_atoi(argv[2]));
                /*
                ** create file locally
                */
                if ((local_fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) != -1)
                {
                    /*
                    ** write to file
                    */
                    ft_wwriten(local_fd, buff, ft_atoi(argv[2]));
                    ft_putendl("ft_p: download complete");
                    close(local_fd);
                }
                else
                    ft_putendl("ft_p: failed to open a file for writing locally");
                ft_strdel(&buff);
            }
        }
    }
}

void           ft_client_get(int fd, char **argv)
{
    char       *req;
    char       *res;

    /*
    ** check that a file was specified
    */
    if (argv[1])
    {
        /*
        ** build server request
        */
        if ((req = ft_strdup("get ")))
        {
            req = ft_wstrjoin(req, argv[1]);
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
                ** server response should be success or error msg 
                ** followed by filename and size
                */
                if (ft_strnequ(res, "OK", 1))
                {
                    /*
                    ** check if the filename exists locally
                    */
                    if (!ft_wfile_exists(res))
                    {
                        /*
                        ** send server request to begin send
                        */
                        ft_send_response("OK\n", fd);
                        /*
                        ** save file locally
                        */
                        ft_save_file(fd, res);
                    }
                    else
                    {
                        ft_send_response("KO", fd);
                        ft_putendl("ft_p: filename is taken locally");
                    }
                }
                else
                    ft_putendl("ft_p: file specified does not exist");
            }
            else
                ft_putendl("ft_p: error recieving file length from server");
        }
        else
            ft_putendl("ft_p: call to malloc failed");      
    }
    else
        ft_putendl("ft_p: file not specified");
}