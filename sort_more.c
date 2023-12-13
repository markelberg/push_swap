#include "push_swap.h"

void    push_b(t_stack   **a, t_stack **b, int  stack_len)
{
    int pushes;
    int i;

    pushes = 0;
    i = 0;
    while (stack_len > pushes + i && pushes < stack_len / 2 && i < stack_len)
    {
        if (*a->index <= (stack_len / 2))
        {
            do_pb(a, b);
            pushes++;
        }
        else
            do_ra(a);
        i++;
    }
    while (stack_len - pushes > 3)
    {
        do_pb(a, b);
        pushes++;
    }
}

void    final_sort(t_stack  **a)
{
    int stack_len;
    int lowest;

    stack_len = check_stack_len(a);
    assign_position(a, NULL);
    lowest = lowest_index(a);
    if (lowest > stack_len / 2)
    {
        while (lowest < stack_len)
        {
            do_rra(a);
            lowest++;
        }
    }
    else
    {
        while (lowest > 0)
        {
            do_ra(a);
            lowest--;
        }
    }
}

int lowest_index(t_stack    **a)
{
    t_stack *tmp;
    int     lowest;
    int     pos;

    tmp = *a->next;
    lowest = INT_MAX;
    while (*a)
    {
        if (*a->index < lowest)
        {
            lowest = *a->index;
            pos = *a->pos;
        }
        *a = *a->next;
    }
    return (pos);

}

void    sort_more(t_stack   **a, t_stack    **b, int    stack_len)
{
    push_b(a, b, stack_len);
    sort_three(a);
    while (*b)
    {
        assign_target(a, b);
        cost(a, b);
        best(a, b);
    }
    if (!is_sorted(*a))
        final_sort(a);
}