/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:59:00 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 21:09:40 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stacks(t_dlist **stack_a, t_dlist **stack_b, t_dlist *cheapest)
{
	while ((*stack_a)->num != cheapest->target
		&& (*stack_b)->num != cheapest->num)
	{
		if (cheapest->target_above && cheapest->above)
			rr(stack_a, stack_b);
		else if (!cheapest->target_above && !cheapest->above)
			rrr(stack_a, stack_b);
		else
			break ;
	}
	while ((*stack_a)->num != cheapest->target)
	{
		if (cheapest->target_above)
			ra(stack_a);
		else
			rra(stack_a);
	}
	while ((*stack_b)->num != cheapest->num)
	{
		if (cheapest->above)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	push_cheapest(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*cheapest;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	iterate_through_b(*stack_b, *stack_a);
	cheapest = find_cheapest(*stack_b);
	rotate_stacks(stack_a, stack_b, cheapest);
	pa(stack_b, stack_a);
}

t_dlist	*find_cheapest(t_dlist *stack_b)
{
	t_dlist	*cheapest;
	size_t	current_cheapest;

	cheapest = NULL;
	current_cheapest = INT_MAX;
	while (stack_b)
	{
		if (stack_b->moves < current_cheapest)
		{
			current_cheapest = stack_b->moves;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest);
}

t_dlist	*stack_max(t_dlist *stack)
{
	t_dlist	*max;
	t_dlist	*head;

	head = stack;
	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->num > max->num)
			max = stack;
		stack = stack->next;
	}
	stack = head;
	return (max);
}

t_dlist	*stack_min(t_dlist *stack)
{
	t_dlist	*min;
	t_dlist	*head;

	head = stack;
	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->num < min->num)
			min = stack;
		stack = stack->next;
	}
	stack = head;
	return (min);
}
