/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:02 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/18 17:24:10 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_above(t_dlist *stack_a, t_dlist **node)
{
	
}

void	actual_sorting(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*min;

	min = NULL;
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		iterate_through_b(*stack_b, *stack_a);
		push_cheapest(stack_a, stack_b);
	}
	min = stack_min(stack_a);
	is_above(stack_a, &min);
	while (!sorted_check(*stack_a))
	{
		if (min->above)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_two(t_dlist **stack)
{
	int	num1;
	int	num2;

	num1 = (*stack)->number;
	num2 = ((*stack)->next)->number;
	if (num1 > num2)
		ra(stack);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		return (0);
	arg_check(argv);
	stack_a = put_lst(argv, argc, stack_a);
	if (argc == 3)
	{
		sort_two(&stack_a);
		return (0);
	}
	actual_sorting(&stack_a, &stack_b);
//	print_lst(stack_a);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
