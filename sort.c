/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:45:49 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 02:01:29 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_moves_conditions(t_dlist *stack_b, t_dlist *current_target)
{
	if (stack_b->above && current_target->above)
	{
		stack_b->moves = stack_b->moves + current_target->moves
			- min_sum(stack_b->moves, current_target->moves);
		stack_b->target_above = true;
	}
	else if (!stack_b->above && !current_target->above)
	{
		stack_b->moves = stack_b->moves + current_target->moves
			- min_sum(stack_b->moves, current_target->moves);
		stack_b->target_above = false;
	}
	else
	{
		if (current_target->above)
			stack_b->target_above = true;
		else
			stack_b->target_above = false;
		stack_b->moves += current_target->moves;
	}
}

void	iterate_through_b(t_dlist *stack_b, t_dlist *stack_a)
{
	t_dlist	*current_target;
	t_dlist	*head_b;
	t_dlist	*head_a;

	head_b = stack_b;
	head_a = stack_a;
	while (stack_b)
	{
		current_target = current_target_node(stack_a, stack_b);
		stack_b->target = current_target->num;
		calculate_to_top(stack_a, current_target);
		calculate_to_top(head_b, stack_b);
		update_moves_conditions(stack_b, current_target);
		stack_b = stack_b->next;
	}
	stack_a = head_a;
	stack_b = head_b;
}

void	calculate_to_top(t_dlist *stack, t_dlist *target_node)
{
	t_dlist	*head;

	head = stack;
	target_node->moves = 0;
	while (stack && stack->num != target_node->num)
	{
		target_node->moves++;
		stack = stack->next;
	}
	if ((ft_dlstsize(head) - target_node->moves) >= target_node->moves)
		target_node->above = true;
	else
	{
		target_node->above = false;
		target_node->moves = ft_dlstsize(head) - target_node->moves;
	}
	stack = head;
}

t_dlist	*current_target_node(t_dlist *s_a, t_dlist *s_b)
{
	t_dlist	*head_a;
	t_dlist	*max;
	t_dlist	*min;

	if (!s_a || !s_b)
		return (NULL);
	head_a = s_a;
	max = stack_max(head_a);
	min = stack_min(head_a);
	if (s_b->num > max->num || s_b->num < min->num)
		return (min);
	while (s_a)
	{
		if (s_a->next == NULL)
		{
			if ((s_b->num > s_a->num) && (s_b->num < head_a->num))
				return (head_a);
		}
		else if ((s_b->num > s_a->num)
			&& (s_b->num < (s_a->next)->num) && s_a->next != NULL)
			return (s_a->next);
		s_a = s_a->next;
	}
	return (min);
}
