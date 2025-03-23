/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:22 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/23 23:44:17 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_dlist **stack_a)
{
	rotate_lst(stack_a);
	ft_printf("ra\n");
}

void	rb(t_dlist **stack_b)
{
	rotate_lst(stack_b);
	ft_printf("rb\n");
}

void	rr(t_dlist **stack_a, t_dlist **stack_b)
{
	rotate_lst(stack_a);
	rotate_lst(stack_b);
	ft_printf("rr\n");
}

void	rra(t_dlist **stack_a)
{
	reverse_rotate_lst(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_dlist **stack_b)
{
	reverse_rotate_lst(stack_b);
	ft_printf("rrb\n");
}
