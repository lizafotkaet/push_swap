/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:22 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 00:41:44 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dlist *stack_a)
{
	swap_lst(stack_a);
	ft_printf("sa\n");
}

void	sb(t_dlist *stack_b)
{
	swap_lst(stack_b);
	ft_printf("sb\n");
}

void	ss(t_dlist *stack_a, t_dlist *stack_b)
{
	swap_lst(stack_a);
	swap_lst(stack_b);
	ft_printf("ss\n");
}

void	pa(t_dlist **stack_b, t_dlist **stack_a)
{
	push_lst(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_dlist **stack_a, t_dlist **stack_b)
{
	push_lst(stack_a, stack_b);
	ft_printf("pb\n");
}
