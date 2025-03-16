/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:59:00 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/16 18:59:47 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
