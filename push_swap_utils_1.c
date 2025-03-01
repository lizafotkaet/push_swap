/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:31:15 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/01 14:52:04 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*put_lst(char **argv, int argc, t_list *stack_a)
{
	t_list	*head;
	t_list	*new_node;
	int		i;
	int		temp;
	int		error;

	head = NULL;
	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i], &error);
		new_node = ft_lstnew(temp);
		duplicates_check(head, temp);
		if (!new_node)
			return (NULL);
		if (!head) // First node
			head = new_node;
		else
			stack_a->next = new_node;
		stack_a = new_node; // Move current node forward
		i++;
	}
	return (head);
}
bool	check_if_sorted(t_list	*lst)
{
	t_list	*head;
	int		current_nbr;

	if (!lst)
		return (true);
	head = lst;
	current_nbr = lst->content;
	while(lst && lst->next)
	{
		lst = lst->next;
		if (current_nbr > lst->content)
			return (false);
		current_nbr = lst->content;
	}
	lst = head;
	return (true);
}

void	free_lst(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}