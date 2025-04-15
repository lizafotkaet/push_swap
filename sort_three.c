/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:59:00 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 01:27:24 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_dlist **head)
{
	int	num_0;
	int	num_1;
	int	num_2;

	num_0 = (*head)->num;
	num_1 = ((*head)->next)->num;
	num_2 = (((*head)->next)->next)->num;
	if (sorted_check(*head))
		return ;
	if (num_0 > num_1 && num_0 < num_2 && num_1 < num_2)
		sa(*head);
	if (num_0 < num_1 && num_0 > num_2 && num_1 > num_2)
		rra(head);
	if (num_0 > num_1 && num_0 > num_2 && num_1 > num_2)
	{
		sa(*head);
		rra(head);
	}
	if (num_0 < num_2 && num_1 > num_2 && num_0 < num_1)
	{
		sa(*head);
		ra(head);
	}
	if (num_0 > num_1 && num_0 > num_2 && num_1 < num_2)
		ra(head);
}

void	push_all_but_three(t_dlist **stack_a, t_dlist **stack_b)
{
	size_t	lst_size;

	lst_size = ft_dlstsize(*stack_a);
	while (lst_size-- > 3)
		pb(stack_a, stack_b);
}
