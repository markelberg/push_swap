#include "push_swap.h"

void    swap(t_stack    **stack)
{
    t_stack *tmp;

    if (!*stack || !*stack->next)
        return ;
    tmp = *stack;
    *stack = *stack->next;
    *stack->next = tmp;
}

void    do_sa(t_stack   **a)
{
    swap(a);
    ft_putstr("sa\n");
}

void    do_sb(t_stack   **b)
{
    swap(b);
    ft_putstr("sb\n");
}

void    do_ss(t_stack   **a, t_stack    **b)
{
    swap(a);
    swap(b);
    ft_putstr("ss\n");
}