#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typdef struct   s_stack
{
    int     value;
    int     index;
    int     target;
    int     pos;
    int     cost_a;
    int     cost_b;
    struct  s_stack *next;
}   t_stack;

t_stack create_node(long int   n)
t_stack bottom_node(t_stack *node)
t_stack before_bottom(t_stack   *stack)
int	    ft_atoi(const char *str)
int     main(int argc, char *argv[])
int     nbrs_repeated(t_stack   *stack)
int     positive(int    cost)
int     is_stack_sorted(t_stack *stack)
int     check_stack_len(t_stack   *stack)
int     check_highest_index(t_stack *stack)
int     get_target(t_stack  **a, t_stack    **b, int    target)
int     lowest_index(t_stack    **a)
void    check_argv(char *argv, t_stack  *a)
void    check_nbrs(char *str)
void    lets_sort(t_stack   **a, t_stack    **b, int    stack_len)
void    swap(t_stack    **stack)
void    do_sa(t_stack   **a)
void    do_sb(t_stack   **b)
void    do_ss(t_stack   **a, t_stack    **b)
void    assign_index(t_stack    *a, int stack_len)
void    sort_three(t_stack  **stack)
void    sort_more(t_stack   **a, t_stack    **b, int    stack_len)
void    push_b(t_stack   **a, t_stack **b, int  stack_len)
void    do_pa(t_stack   **a, t_stack    **b)
void    do_pb(t_stack   **a, t_stack    **b)
void    rotate(t_stack  **stack)
void    do_ra(t_stack  **a)
void    do_rb(t_stack  **b)
void    do_rr(t_stack   **a, t_stack    **b)
void    reverse_rotate(t_stack  **stack)
void    do_rra(t_stack  **a)
void    do_rrb(t_stack  **b)
void    do_rrr(t_stack  **a, t_stack    **b)
void    ft_putstr(char  *str)
void    assign_target(t_stack  **a, t_stack    **b)
void    assign_position(t_stack    **a, t_stack **b)
void    cost(t_stack    **a, t_stack    **b)
void    best(t_stack    **a, t_stack    **b)
void    which_move(t_stack **a, t_stack    **b, int    cost_a, int cost_b)
void    reverse_rotate_ab(t_stack   **a, t_stack    **b, int    *cost_a, int    *cost_b)
void    rotate_ab(t_stack   **a, t_stack    **b, int    *cost_a, int    *cost_b)
void    move_a(t_stack    **a, int    *cost_a)
void    move_b(t_stack    **b, int    *cost_b)
void    final_sort(t_stack  **a)
void    error(t_stack   **a, t_stack    **b)
void    free_stack(t_stack  **stack)