/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:02 by ebarbash          #+#    #+#             */
/*   Updated: 2025/05/21 18:23:01 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_above(t_dlist *stack_a, t_dlist *node)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_dlstsize(stack_a);
	while (stack_a != node)
	{
		stack_a = stack_a->next;
		i++;
	}
	if (i > size / 2)
		node->above = false;
	else
		node->above = true;
}

void	actual_sorting(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*min;
	t_dlist	**head;

	min = NULL;
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		iterate_through_b(*stack_b, *stack_a);
		push_cheapest(stack_a, stack_b);
	}
	head = stack_a;
	min = stack_min(*stack_a);
	is_above(*stack_a, min);
	while (min != *head)
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

	num1 = (*stack)->num;
	num2 = ((*stack)->next)->num;
	if (num1 > num2)
		ra(stack);
}

bool	arg_check_for_one(int argc, char **argv)
{
	int		error;

	if (argc == 2)
	{
		ft_atoi(argv[1], &error);
		if (!is_valid_number(argv[1]) || error == 1)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else
			return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (arg_check_for_one(argc, argv))
		return (0);
	arg_check(argv);
	stack_a = put_lst(argv, argc, stack_a);
	if (sorted_check(stack_a))
		return (free_lst(&stack_a), 0);
	if (argc == 3)
	{
		sort_two(&stack_a);
		return (free_lst(&stack_a), 0);
	}
	actual_sorting(&stack_a, &stack_b);
	return (free_lst(&stack_a), free_lst(&stack_b), 0);
}
