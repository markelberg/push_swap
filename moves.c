#include "push_swap.h"

void    which_move(t_stack **a, t_stack    **b, int    cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        reverse_rotate_ab(a, b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        rotate_ab(a, b, &cost_a, &cost_b);
    move_a(a, &cost_a);
    move_b(b, &cost_b);
    do_pa(a, b);
}

void    reverse_rotate_ab(t_stack   **a, t_stack    **b, int    *cost_a, int    *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        *cost_a++;
        *cost_b++;
        do_rrr(a, b);
    }
}

void    rotate_ab(t_stack   **a, t_stack    **b, int    *cost_a, int    *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        *cost_a--;
        *cost_b--;
        do_rr(a, b);
    }
}

void    move_a(t_stack    **a, int    *cost_a)
{
    while (*cost_a != 0)
    {
        if (*cost_a > 0)
        {
            do_ra(a);
            *cost_a--;
        }
        else if (*cost_a < 0)
        {
            do_rra(a);
            *cost_a++
        }
    }
}

void    move_b(t_stack    **b, int    *cost_b)
{
    while (*cost_b != 0)
    {
        if (*cost_b > 0)
        {
            do_rb(b);
            *cost_b--;
        }
        else if (*cost_b < 0)
        {
            do_rra(b);
            *cost_b++
        }
    }
}