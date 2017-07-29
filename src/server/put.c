# include <ft_p.h>

void           ft_server_put(int connfd, char **argv)
{
    int        fd;
    char       *buff;

    /*
    ** check if client passed correct argument
    */
    if (ft_dstrlen(argv) == 3)
    {
        if (ft_file_exists(argv[1]))
        {
            ft_send_response("KKO\n", connfd);
        }
        else
        {
            if ((buff = ft_strnew(ft_atoi(argv[2]))))
            {
                /*
                ** tell client to proceed to step 2
                */
                ft_send_response("OK\n", connfd);
                /*
                ** wait for data
                */
                ft_wreadn(connfd, buff, ft_atoi(argv[2]));
                /*
                ** create file
                */
                if ((fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) != -1)
                {
                    ft_wwriten(fd, buff, ft_atoi(argv[2]));
                    ft_send_response("OK\n", connfd);
                }
                else
                    ft_send_response("KO\n", connfd);
            }
            else
                ft_send_response("KO\n", connfd);
        }
    }
    else
    {
        ft_send_response("KO\n", connfd);
    }

}