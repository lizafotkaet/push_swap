/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:02 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/01 15:12:25 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	bubble_s(t_list **stack_a, t_list **stack_b)
{
	
}


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		error;

	error = 0;
	stack_a = NULL;
	if (argc <= 1)
		return (-1);
	arg_check(argv);
	stack_a = put_lst(argv, argc, stack_a);
	print_lst(stack_a);

	free_lst(&stack_a);
	return (0);
}
