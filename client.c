/*#include "minitalk.h"
#include <stdio.h>
t_minitalk *client_init()
{
    t_minitalk *pids;
    pids = malloc(sizeof(pids));
    if(!pids)
    {
        ft_putstr("Malloc allocation for client failed");
        exit(EXIT_FAILURE);
    }
    pids->pid_client = 0;
    pids->pid_client = 0;
    return(pids);
}
void send_message(t_minitalk *pids, char * message)
{
    int bit_displ;
    int i;
    int signal;
    bit_displ = 0;
    i = 0;
    while((bit_displ <= 8))
    {
        if((message[i] >> bit_displ) & 1)
            signal = SIGUSR2;
        else
            signal = SIGUSR1;
        if(kill(pids->pid_server, signal) == -1);
            {
                perror("Error en kill:");
                return;
            }
        
        usleep(200);
        i++;
        bit_displ++;
    }
    return ; 
}
int main(int argc, char** argv)
{
    t_minitalk *pids;
    if(argc != 3)
    {
        ft_putstr("You can only use \"./server\" with 3 arguments: \"./server\" \"PID\" \"Message to send\"");
        exit(EXIT_FAILURE);
    }
    else
    {
        pids = client_init();
        pids->pid_server = atoi(argv[1]);
        if(pids <= 0)
        {
            ft_putstr("PID can't be <= 0");
            free(pids);
            return(EXIT_FAILURE);
        }
        send_message(pids, argv[2]);
    }
    return(EXIT_SUCCESS);
}*/