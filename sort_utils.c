/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:22 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/11 17:41:14 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*stack_max(t_dlist *stack)
{
	t_dlist		*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->number > max->number)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_dlist	*stack_min(t_dlist *stack)
{
	t_dlist	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->number < min->number)
			min = stack;
		stack = stack->next;
	}
	return (min);
}