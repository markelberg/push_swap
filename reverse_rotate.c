#include "push_swap.h"

void    reverse_rotate(t_stack  **stack)
{
    t_stack *tmp;
    t_stack *bottom;
    t_stack *bef_bottom;

    tmp = *stack;
    bottom = bottom_node(*stack);
    bef_bottom = before_bottom(*stack);
    bottom = *stack;
    bef_bottom->next = NULL;
    *stack->next = tmp;
}

t_stack before_bottom(t_stack   *stack)
{
    while (stack && stack->next->next != NULL)
    {
        stack = stack->next;
    }
    return (stack);
}

void    do_rra(t_stack  **a)
{
    reverse_rotate(a);
    ft_putstr("rra\n");
}

void    do_rrb(t_stack  **b)
{
    reverse_rotate(b);
    ft_putstr("rrb\n");
}

void    do_rrr(t_stack  **a, t_stack    **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr("rrr\n");
}