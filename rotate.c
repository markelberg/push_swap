#include "push_swap.h"

void    rotate(t_stack  **stack)
{
    t_stack *tmp;
    t_stack *bottom;

    tmp = *stack;
    bottom = bottom_node(*stack);
    *stack = *stack->next;
    tmp->next = NULL;
    bottom->next = tmp;
}

t_stack bottom_node(t_stack *node)
{
    if (!node)
        return (NULL);
    while (node && node->next != NULL)
        node = node->next;
    return (node);
}

void    do_ra(t_stack  **a)
{
    rotate(a);
    ft_putstr("ra\n");
}

void    do_rb(t_stack  **b)
{
    rotate(b);
    ft_putstr("rb\n");
}

void    do_rr(t_stack   **a, t_stack    **b)
{
    rotate(a);
    rotate(b);
    ft_putstr("rr\n");
} 