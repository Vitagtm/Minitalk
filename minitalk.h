#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct s_minitalk
{
    int pid_server;
    int pid_client;
} t_minitalk;

t_minitalk* serv_init();
void write_message(int bit);
void server_listen(t_minitalk *pids);
t_minitalk *pid_init();
void send_message(char * message, t_minitalk *pid);
void ft_putstr(char * str);
void ft_putnbr(int num);
int	ft_atoi(const char *str);


#endif