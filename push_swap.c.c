#include "push_swap.h"

void    lets_sort(t_stack   **a, t_stack    **b, int    stack_len)
{
    if (stack_len == 2 && !is_stack_sorted(a))
        do_sa(a);
    else if (stack_len == 3 && !is_stack_sorted(a))
        sort_three(a);
    else if (stack_len > 3 && !is_stack_sorted(a))
        sort_more(a, b, stack_len);
}

t_stack create_node(long int   n)
{
    t_stack new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!a)
        return (NULL);
    new_node->value = n;
    new_node->next = NULL;
    new_node->index = 0;
    new_node->target = 0;
    new_node->pos = 0;
    new_node->cost_a = 0;
    new_node->cost_b = 0;
    return (new_node);
}

void    check_nbrs(char *str)
{
    int i;

    i = 0;
    if (str[0] == '-' || str[0] == '+' && ft_strlen(str) > 1)
        i++;
    while (str[i])
    {
        if (str[i] < 48 || str[i] > 57)
            return (NULL);
        i++;
    }
}

void    check_argv(char *argv, t_stack  *a)
{
    char        **split_nbrs;
    long int    n;
    int         i;

    i = 0;
    split_nbrs = ft_split(argv, ' ');
    while (split_nbrs[i])
    {
        check_nbrs(split_nbrs[i])
        n = ft_atoi(split_nbrs[i]);
        if (n < INT_MIN || n > INT_MAX)
            return (NULL);
        a = create_node(n);
        a = a->next;
        i++;
    }
    free(split_nbrs);
}

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    int     i;
    int     stack_len;

    a = NULL;
    b = NULL;
    i = 1;
    if (argc == 1)
        return (NULL);
    while (++i < argc)
        check_argv(argv[i], &a);
    stack_len = check_stack_len(a);
    if (nbrs_repeated(a))
    {
        error(&a, NULL);
        return (1);
    }
    assign_index(a, stack_len);
    lets_sort(&a, &b, stack_len);
    free_stack(&a);
    free_stack(&b);
    return (0);
}