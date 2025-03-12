/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:02 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/11 18:18:52 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (-1);

	arg_check(argv);
	stack_a = put_lst(argv, argc, stack_a);
	push_all_but_three(&stack_a, &stack_b);

	ft_printf("Stack b after pushing:\n");
	print_lst(stack_b);
	ft_printf("\n");
	sort_three(&stack_a);
	ft_printf("Stack a after sort 3:\n");
	print_lst(stack_a);
	ft_printf("\n");

	ft_printf("Target nodes:\n");
	target_nodes(stack_b, stack_a);
	ft_printf("\n");















	
	// ft_printf("Stack a after pushing:\n");
	// print_lst(stack_a);
	// ft_printf("Stack a at input:\n");
	// print_lst(stack_a);
	// ft_printf("\n");
	// ft_printf("Before pushing:\n");
	// ft_printf("Stack a:\n");
	// print_lst(stack_a);
	// ft_printf("Stack b:\n");
	// print_lst(stack_b);
	// push_all_but_three(&stack_a, &stack_b);
	// ft_printf("After pushing:\n");
	// ft_printf("Stack a:\n");
	// print_lst(stack_a);
	// ft_printf("Stack b:\n");
	// print_lst(stack_b);


	// if (sorted_check(stack_a))
	// 	ft_printf("Sorted\n");
	// else
	// 	ft_printf("Unsorted;\n");
	// swap_lst(stack_a);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
