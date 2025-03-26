#include "minitalk.h"

void ft_putstr(char * str)
{
    int i;
    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void	ft_putnbr(int num)
{
	char	c;

	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = -num;
			ft_putnbr(num);
		}
		else if (num < 10)
		{
			c = num + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(num / 10);
			c = (num % 10) + '0';
			write(1, &c, 1);
		}
	}
}
int	ft_atoi(const char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}