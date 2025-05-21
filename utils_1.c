/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:31:15 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 01:33:35 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_nodes(t_dlist **new_node, t_dlist **head, t_dlist **stack_a)
{
	if (!*new_node)
		return ;
	if (!*head)
	{
		*head = *new_node;
		(*head)->prev = NULL;
	}
	else
	{
		(*stack_a)->next = *new_node;
		(*new_node)->prev = *stack_a;
	}
}

t_dlist	*put_lst(char **argv, int argc, t_dlist *stack_a)
{
	t_dlist	*head;
	t_dlist	*new_node;
	int		i;
	int		temp;

	head = NULL;
	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i], NULL);
		new_node = ft_dnew_node(temp);
		duplicates_check(head, temp);
		put_nodes(&new_node, &head, &stack_a);
		stack_a = new_node;
		i++;
	}
	return (head);
}

bool	is_valid_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

void	duplicates_check(t_dlist *lst, int nbr)
{
	while (lst)
	{
		if (nbr == lst->num)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		lst = lst->next;
	}
}

void	arg_check(char **argv)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (argv[i])
	{
		if (is_valid_number(argv[i]) == false)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		ft_atoi(argv[i], &error);
		if (error == 1)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
