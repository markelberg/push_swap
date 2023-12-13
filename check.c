#include "push_swap.h"

void    free_stack(t_stack  **stack)
{
    if (!stack || !*stack)
        return ;
    while (*stack)
    {
        tmp = *stack->next;
        free(*stack);
        *stack = tmp;
    }
}

void    error(t_stack   **a, t_stack    **b)
{
    if (!a || !*a)
        free_stack(a);
    if (!b || !*b)
        free_stack(b);
    ft_putstr("Error\n");
}

int nbrs_repeated(t_stack   *stack)
{
    t_stack *tmp;
    t_stack *tmp2;

    tmp = stack;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->value == tmp2->value)
                return (1);
            tmp2 = tmp2->next
        }
        tmp = tmp->next;
    }
    return (0);
}

int is_stack_sorted(t_stack *stack)
{
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}