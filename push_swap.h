/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:12 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 01:31:31 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct d_list
{
	struct d_list	*prev;
	int				num;
	bool			above;
	int				target;
	bool			target_above;
	size_t			moves;
	struct d_list	*next;
}	t_dlist;

// dll functions:

t_dlist	*ft_lst_nexttolast(t_dlist *lst);
t_dlist	*ft_dnew_node(int number);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlsthead(t_dlist *lst);
size_t	ft_dlstsize(t_dlist *lst);
t_dlist	*put_lst(char **argv, int argc, t_dlist *stack_a);
void	put_nodes(t_dlist **new_node, t_dlist **head, t_dlist **stack_a);
void	print_lst(t_dlist *lst);
void	free_lst(t_dlist **lst);

// checks functions:

void	arg_check(char **argv);
void	duplicates_check(t_dlist *lst, int nbr);
bool	is_valid_number(const char *str);
bool	sorted_check(t_dlist	*lst);
bool	arg_check_for_one(int argc, char **argv);
// moves:

void	swap_lst(t_dlist *head);
void	push_lst(t_dlist **head_a, t_dlist **head_b);
void	rotate_lst(t_dlist **head);
void	reverse_rotate_lst(t_dlist **head);
void	sa(t_dlist *stack_a);
void	sb(t_dlist *stack_b);
void	ss(t_dlist *stack_a, t_dlist *stack_b);
void	pa(t_dlist **stack_b, t_dlist **stack_a);
void	pb(t_dlist **stack_a, t_dlist **stack_b);
void	ra(t_dlist **stack_a);
void	rb(t_dlist **stack_b);
void	rr(t_dlist **stack_a, t_dlist **stack_b);
void	rra(t_dlist **stack_a);
void	rrb(t_dlist **stack_b);
void	rrr(t_dlist **stack_a, t_dlist **stack_b);

// actual sorting:

void	sort_two(t_dlist **stack);
void	sort_three(t_dlist **head);
void	push_all_but_three(t_dlist **stack_a, t_dlist **stack_b);
t_dlist	*stack_max(t_dlist *stack);
t_dlist	*stack_min(t_dlist *stack);
t_dlist	*current_target_node(t_dlist *stack_a, t_dlist *stack_b);
void	calculate_to_top(t_dlist *stack, t_dlist *target_node);
void	update_moves_conditions(t_dlist *stack_b, t_dlist *current_target);
void	iterate_through_b(t_dlist *stack_b, t_dlist *stack_a);
t_dlist	*find_cheapest(t_dlist *stack_b);
void	rotate_stacks(t_dlist **stack_a, t_dlist **stack_b, t_dlist *cheapest);
void	push_cheapest(t_dlist **stack_a, t_dlist **stack_b);
void	actual_sorting(t_dlist **stack_a, t_dlist **stack_b);
void	is_above(t_dlist *stack_a, t_dlist *node);

// assorted crap lmao

int		min_sum(int a, int b); // returns the minimum of two numbers
