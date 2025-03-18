/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:22 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/18 17:22:51 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack->number > max->number)
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
		if (stack->number < min->number)
			min = stack;
		stack = stack->next;
	}
	stack = head;
	return (min);
}