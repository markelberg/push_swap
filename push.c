#include "push_swap.h"

void    push(t_stack    **stack1, t_stack   **stack2)
{
    t_stack *tmp

    tmp = *stack1->next
    *stack1->next = *stack2;
    *stack2 = *stack1;
    *stack1 = tmp;
}

void    do_pa(t_stack   **a, t_stack    **b)
{
    push(b, a);
    ft_putstr("pa\n");
}

void    do_pb(t_stack   **a, t_stack    **b)
{
    push(a, b);
    ft_putstr("pb\n");
}