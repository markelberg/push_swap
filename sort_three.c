#include "push_swap.h"

int check_highest_index(t_stack *stack)
{
    int tmp;

    tmp = stack->index;
    while (stack)
    {
        stack = stack->next;
        if (stack->index > tmp)
            tmp = stack->index;
    }
    return (tmp);
}

void    sort_three(t_stack  **stack)
{
    int highest;
    
    highest = check_highest_index(*stack);
    if (*stack->index == highest)
        do_ra(stack);
    else if (*stack->next->index == highest)
        do_rra(stack);
    if (*stack->index > *stack->next->index)
        do_sa(stack);
}