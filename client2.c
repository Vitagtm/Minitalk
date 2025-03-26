#include "minitalk.h"
#include <stdio.h>

t_minitalk *pid_init()
{
    t_minitalk *pids;
    pids = malloc(sizeof(t_minitalk));
    if(!pids)
    {
        ft_putstr("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    pids->pid_server = 0;
    pids->pid_client = 0;
    return(pids);
}
void send_message(char * message, t_minitalk *pid)
{
    int i;
    int bit_displ;
    i = 0;
    int bit;
    
    while(message[i])
    {
        bit_displ = 0;
        ft_putstr("Enter send_message function\n");
        while(bit_displ < 8)
        {
            if((message[i] >> bit_displ) & 1)
                kill(pid->pid_server, SIGUSR2);
            else
                kill(pid->pid_server, SIGUSR1);
            usleep(200);
            bit_displ++;
        }
        printf("%c has been sent\n", message[i]);
        i++;
    }
}
int main(int argc, char ** argv)
{
    t_minitalk *pids;

    if(argc != 3)
    {
        ft_putstr("The number of arguments is not valid. Try with \"./client ServerPID \"Message to send\".");
        exit(EXIT_FAILURE);
    }
    pids = pid_init();
    pids->pid_server = atoi(argv[1]);
    if(pids->pid_server <= 0)
    {
        ft_putstr("Server PID is not valid.");
        return(EXIT_FAILURE);
    }
    send_message(argv[2], pids);
    return(EXIT_SUCCESS);

}