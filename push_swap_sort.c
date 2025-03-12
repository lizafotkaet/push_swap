/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:45:49 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/11 20:28:46 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iterate_through_b(t_dlist *stack_b, t_dlist *stack_a) // COUNT ONLY ROTATE (figure out later)
{
	size_t	count_rb;
	size_t	count_total;
	t_dlist	*current_target;
	t_dlist	*head_b;

	count_rb = 0;
	count_total = 0;
	current_target = NULL;
	head_b = stack_b;
	while (stack_b)
	{
		current_target = current_target_node(stack_a, stack_b);
		count_total += calculate_ra(stack_a, current_target);
		count_rb++;
		stack_b = 
	}
}

size_t	calculate_ra(t_dlist *stack, t_dlist *target_node) // calculates how many moves we need to get the CURRENT b node in the right position
{
	size_t	ra_count;
	t_dlist	*head;

	head = stack;
	ra_count = 0;
	while (stack != target_node)
	{
		stack = stack->next;
		ra_count++;
	}
	stack = head;
	return (ra_count);		
}

bool	ra_or_rra(size_t ra_count, t_dlist	*stack) // true - rotate, false - reverse rotate
{
	if (ra_count > (ft_dlstsize(stack) - ra_count))
		return (false);
	else if (ra_count == (ft_dlstsize(stack) - ra_count))
		return (true);
	else
		return (true);	
}

t_dlist	*current_target_node(t_dlist *stack_a, t_dlist *stack_b)
{
	t_dlist	*head_a;
	t_dlist	*max;
	t_dlist	*min;

	if (!stack_a || !stack_b)
		return (NULL);
	head_a = stack_a;
	max = stack_max(head_a);
	min = stack_min(head_a);
	if (stack_b->number > max->number)
		return (min);
	if (stack_b->number < min->number)
		return (min);
	while (stack_a)
	{
		if (stack_a->next == NULL)
		{
			if ((stack_b->number > stack_a->number) && (stack_b->number < head_a->number))
				return (head_a);
		}
		else if ((stack_b->number > stack_a->number) && (stack_b->number < (stack_a->next)->number) && stack_a->next != NULL)
			return (stack_a->next);
		stack_a = stack_a->next;
	}
	return (min);
}

void	sort_three(t_dlist **head)
{
	int	num_0;
	int	num_1;
	int	num_2;

	num_0 = (*head)->number;
	num_1 = ((*head)->next)->number;
	num_2 = (((*head)->next)->next)->number; 
	if (sorted_check(*head))
		return ;
	if (num_0 > num_1 && num_0 < num_2) // 2 1 3
		swap_lst(*head);
	if (num_0 < num_1 && num_0 > num_2) // 2 3 1
		reverse_rotate_lst(head);
	if (num_0 > num_1 && num_0 > num_2) // 3 2 1
	{
		swap_lst(*head);
		reverse_rotate_lst(head);
	}
	if (num_0 < num_2 && num_1 > num_2) // 1 3 2
	{
		swap_lst(*head);
		rotate_lst(head);
	}
	if (num_0 > num_1 && num_0 > num_2 && num_1 < num_2) // 3 1 2
		rotate_lst(head);
}

void	push_all_but_three(t_dlist **stack_a, t_dlist **stack_b)
{
	while(ft_dlstsize(*stack_a) != 3)
		push_lst(stack_a, stack_b);
}

// void	target_nodes(t_dlist *stack_b, t_dlist *stack_a)
// {
// 	t_dlist	*current;

// 	current = NULL;
// 	while (stack_b)
// 	{
// 		current = current_target_node(stack_a, stack_b);
// 		ft_printf("Target node for %d: %d\n", stack_b->number, current->number);
// 		stack_b = stack_b->next;
// 	}

// bool	is_rrb_cheaper(t_dlist *stack_b, t_dlist *head_b) // how many rb it takes to get to current stack b node and whether we should switch to rrb
// {
// 	size_t	rotations;

// 	rotations = 0;
// 	while (head_b != stack_b)
// 	{
// 		head_b = head_b->next;
// 		rotations++;
// 	}
// 	if (rotations > (ft_dlstsize(head_b) - rotations))
// 		return (false); // reverse rotate then
// 	return (true); // regular rotate then
// }
// }