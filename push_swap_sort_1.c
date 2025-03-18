/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:59:00 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/17 18:59:27 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_dlist **head)
{
	int	num_0;
	int	num_1;
	int	num_2;

	num_0 = (*head)->number;
	ft_printf("here\n%d\n", num_0);
	num_1 = ((*head)->next)->number;
	ft_printf("here");
	num_2 = (((*head)->next)->next)->number;
	ft_printf("here");
	if (sorted_check(*head))
		return ;
	if (num_0 > num_1 && num_0 < num_2) // 2 1 3
		sa(*head);
	if (num_0 < num_1 && num_0 > num_2) // 2 3 1
		rra(head);
	if (num_0 > num_1 && num_0 > num_2) // 3 2 1
	{
		sa(*head);
		rra(head);
	}
	if (num_0 < num_2 && num_1 > num_2) // 1 3 2
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
	print_lst(*stack_a);
}
