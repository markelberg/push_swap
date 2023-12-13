#include "push_swap.h"

void    cost(t_stack    **a, t_stack    **b)
{
    int len_a;
    int len_b;

    len_a = check_stack_len(a);
    len_b = check_stack_len(b);
    while (*b)
    {
        *b->cost_b = *b->pos;
        if (*b->pos > len_b / 2)
            *b->cost_b = (len_b - *b->pos) * -1;
        *b->cost_a = *b->target;
        if (*b->target > len_a / 2)
            *b->cost_a = (len_a - *b->target) * -1;
        *b = *b->next;
    }
}

void    best(t_stack    **a, t_stack    **b)
{
    int best;
    int cost_b;
    int cost_a;

    best = INT_MAX;
    while (*b)
    {
        if ((positive(*b->cost_b)+ positive(*b->cost_a)) < best)
        {
            best = positive(*b->cost_b) + positive(*b->cost_a);
            cost_b = *b->cost_b;
            cost_a = *b->cost_a;
        }
        *b = *b->next;
    }
    which_move(a, b, cost_b, cost_a);
}