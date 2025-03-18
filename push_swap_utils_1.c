/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:31:15 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/17 18:53:45 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_nodes(t_dlist **new_node, t_dlist **head, t_dlist **stack_a)
{
	if (!*new_node)
		return ;
	if (!*head) // first node!!!!!!!!!!!!!!!!!!!!
	{
		*head = *new_node;
		(*head)->prev = NULL; // cause node 1 points to nothing!!!!!!
	}
	else
	{
		(*stack_a)->next = *new_node; // stack->next currently previous SO gotta link the ___previous____ (*next) node to the new one (which is where *next is supposed to point now)
		(*new_node)->prev = *stack_a; // Set the previous pointer of the new node to the actual previous node (which is currently stack_a, and new_node is next)
	}
}

t_dlist	*put_lst(char **argv, int argc, t_dlist *stack_a)
{
	t_dlist	*head;
	t_dlist	*new_node;
	int		i;
	int		index;
	int		temp;

	head = NULL;
	stack_a = NULL;
	i = 1;
	index = 0;
	while (i < argc)
	{
		temp = ft_atoi(argv[i], NULL);
		new_node = ft_dnew_node(temp);
		duplicates_check(head, temp);
		put_nodes(&new_node, &head, &stack_a);
		stack_a = new_node; // move current node forward (duh)
		i++;
		index++;
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
	while(lst)
	{
		if (nbr == lst->number)
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

	i = 0;
	error = 0;
	while (argv[i])
	{
		if (is_valid_number(argv[i]) == false)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		ft_atoi(argv[i], &error);
		if (error)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
