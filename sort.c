/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:45:49 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/23 22:57:19 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheapest(t_dlist **stack_a, t_dlist **stack_b) // from stack b to stack a!!!!
{
	t_dlist	*cheapest;

	if (!stack_a || !stack_b || !*stack_b) // why i don't know but let it be 
		return ;
	iterate_through_b(*stack_b, *stack_a);
	cheapest = find_cheapest(*stack_b);
	while ((*stack_a)->number != cheapest->target && (*stack_b)->number != cheapest->number) // common rotations
	{
		if (cheapest->target_above && cheapest->above)
			rr(stack_a, stack_b);
		else if (!cheapest->target_above && !cheapest->above)
			rrr(stack_a, stack_b);
		else
			break ;
	}
	while ((*stack_a)->number != cheapest->target) // then stack a
	{
		if (cheapest->target_above)
			ra(stack_a);
		else
			rra(stack_a);
	}
	while ((*stack_b)->number != cheapest->number) // then stack b
	{
		if (cheapest->above)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	pa(stack_b, stack_a);
}

t_dlist	*find_cheapest(t_dlist *stack_b) // cheapest element in stack B!!!!
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

void	iterate_through_b(t_dlist *stack_b, t_dlist *stack_a) // SUPPOSED TO CALCULATE THE MOVES FOR ALL OF B
{
	t_dlist	*current_target;
	t_dlist	*head_b;
	t_dlist	*head_a;

	current_target = NULL;
	head_b = stack_b;
	head_a = stack_a;
	while (stack_b)
	{
		current_target = current_target_node(stack_a, stack_b);
		stack_b->target = current_target->number;
		if (current_target)
		calculate_to_top(stack_a, current_target);
		calculate_to_top(head_b, stack_b);
		if (stack_b->above && current_target->above)
		{
			stack_b->moves = stack_b->moves + current_target->moves - min_sum(stack_b->moves, current_target->moves);
			stack_b->target_above = true;
		}
		else if (!stack_b->above && !current_target->above)
		{
			stack_b->moves = stack_b->moves + current_target->moves - min_sum(stack_b->moves, current_target->moves);
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
		stack_b = stack_b->next;
	}
	stack_a = head_a;
	stack_b = head_b;
}

void	calculate_to_top(t_dlist *stack, t_dlist *target_node) // calculates how many moves it takes to get the target node to the top of ANY stack
{
	t_dlist	*head;

	head = stack;
	target_node->moves = 0;
	while (stack && stack->number != target_node->number)
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
