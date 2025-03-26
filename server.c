#include "minitalk.h"
t_minitalk* serv_init()
{
    t_minitalk *pids;

    pids = malloc(sizeof(t_minitalk));
    if(!pids)
    {
        ft_putstr("ERROR! Malloc failed! \n");
        exit(EXIT_FAILURE);
    }
    pids->pid_client = 0;
    pids->pid_server = 0;
    return(pids);
}
void write_message(int bit)
{
    static char letter;
    static int bit_displ;
    //ft_putstr("Enter write_message function\n");
    if(bit == SIGUSR2)
        bit = 1;
    else
        bit = 0;
    letter |= (bit & 1) << bit_displ++;
    if(bit_displ == 8)
    {
        write(1, &letter, 1);
        bit_displ= 0;
        letter = 0;
    }
    return ;

}
void server_listen(t_minitalk *pids)
{
    if((signal(SIGUSR1, write_message) == SIG_ERR)||(signal(SIGUSR2, write_message) == SIG_ERR))
    {
        ft_putstr("Signal error");
        free(pids);
        exit(EXIT_FAILURE);
    }
    while(1)
        pause();
}
int main(int argc, char** argv)
{
    t_minitalk *pids;
    if(argc != 1)
    {
        ft_putstr("Server only needs 1 argument");
        exit(EXIT_FAILURE);
    }
    else
    {
        pids = serv_init();
        pids->pid_server = getpid();
        ft_putstr("Server PID is ready:");
        ft_putnbr(pids->pid_server);
        ft_putstr("\n");
        server_listen(pids);
    }
    return(EXIT_SUCCESS);
}