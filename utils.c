#include "push_swap.h"

int check_stack_len(t_stack   *stack)
{
    int len;

    len = 0;
    if (!stack)
        return (NULL);
    while(stack)
    {
        stack = stack->next;
        len++;
    }
    return (len);
}

int positive(int    cost)
{
    if (cost < 0)
        return (cost * -1);
    return (cost);
}

void    ft_putstr(char  *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int	ft_atoi(const char *str)
{
	int	i;
	int	at;
	int	sign;

	i = 0;
	at = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		at = at * 10 + (str[i] - 48);
		i++;
	}
	return (at * sign);
}