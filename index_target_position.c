#include "push_swap.h"

void    assign_index(t_stack    *a, int stack_len)
{
    t_stack *tmp;
    t_stack *highest_node;
    int     node_value;

    while (stack_len > 0)
    {
        tmp = a;
        highest_node = NULL;
        node_value = INT_MIN;
        while (tmp)
        {
            if (tmp->value > node_value && tmp->index == 0)
            {
                node_value = tmp->value;
                highest_node = tmp;
                tmp = tmp->next;
            }
                else
                    tmp = tmp->next;
        }
        if (highest_node)
            highest_node->index = stack_len;
        stack_len--;
    }
}

void    assign_target(t_stack  **a, t_stack    **b)
{
    int     target;

    target = 0;
    assign_position(a, b);
    while (*b)
    {
        target = get_target(a, b, target);
        *b->target = target;
        *b = *b->next;
    }
}

int get_target(t_stack  **a, t_stack    **b, int    target)
{
    t_stack *tmp;
    int     aux;

    tmp = *a;
    aux = INT_MAX;
    while (tmp)
    {
        if (tmp->index > *b->index && tmp->index < aux)
        {
            target = tmp->pos;
            aux = tmp->index;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL && aux != INT_MAX)
        return (target);
    while (*a)
    {
        if (*a->index < aux)
        {
            aux = *a->index;
            target = *a->pos;
        }
        *a = *a->next;
    }
    return (target);
}

void    assign_position(t_stack    **a, t_stack **b)
{
    int     i;

    i = 0;
    while (*a)
    {
        *a->pos = i;
        *a = *a->next;
        i++;
    }
    i = 0;
    while (*b)
    {
        *b->pos = i;
        *b = *b->next;
        i++;
    }
}