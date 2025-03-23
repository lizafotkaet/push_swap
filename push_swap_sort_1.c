/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:59:00 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/23 12:55:13 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (num_0 > num_1 && num_0 < num_2 && num_1 < num_2) // 2 1 3
		sa(*head);
	if (num_0 < num_1 && num_0 > num_2 && num_1 > num_2) // 2 3 1
		rra(head);
	if (num_0 > num_1 && num_0 > num_2 && num_1 > num_2) // 3 2 1
	{
		sa(*head);
		rra(head);
	}
	if (num_0 < num_2 && num_1 > num_2 && num_0 < num_1) // 1 3 2
	{
		sa(*head);
		ra(head);
	}
	if (num_0 > num_1 && num_0 > num_2 && num_1 < num_2) // 3 1 2
		ra(head);
}

void	push_all_but_three(t_dlist **stack_a, t_dlist **stack_b)
{
	size_t	lst_size;
	
	lst_size = ft_dlstsize(*stack_a);
	while(lst_size-- > 3)
		pb(stack_a, stack_b);
}
