/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:02 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/04 17:42:58 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	bubble_s(t_list **stack_a, t_list **stack_b)
// {
	
// }


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
	ft_printf("Before reverse rotate:\n");
	ft_printf("Stack a:\n");
	print_lst(stack_a);
//	ft_printf("Stack b:\n");
//	print_lst(stack_b);
	reverse_rotate_lst(&stack_a);
	ft_printf("After reverse rotate:\n");
	ft_printf("Stack a:\n");
	print_lst(stack_a);
//	ft_printf("Stack b:\n");
//	print_lst(stack_b);
	free_lst(&stack_a);
	free_lst(&stack_b);


	// if (sorted_check(stack_a))
	// 	ft_printf("Sorted\n");
	// else
	// 	ft_printf("Unsorted;\n");
	// swap_lst(stack_a);

	return (0);
}
