/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:02 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/17 19:07:09 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actual_sorting(t_dlist **stack_a, t_dlist **stack_b)
{
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (!sorted_check(*stack_a) && (*stack_b))
	{
		iterate_through_b(*stack_b, *stack_a);
		push_cheapest(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	char	**arguments;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (-1);
	if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		while (arguments)
		{
			ft_printf("%s\n", arguments);
			arguments++;
		}
	}
	else
	{
		argv++;
		arguments = argv;
	}
	arg_check(arguments);
	stack_a = put_lst(arguments, argc, stack_a);
	actual_sorting(&stack_a, &stack_b);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
