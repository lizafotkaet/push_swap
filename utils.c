/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:25:03 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 01:32:23 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_dlist *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->num);
		lst = lst->next;
	}
}

bool	sorted_check(t_dlist	*lst)
{
	t_dlist	*head;
	int		current_nbr;

	if (!lst)
		return (true);
	head = lst;
	current_nbr = lst->num;
	while (lst && lst->next)
	{
		lst = lst->next;
		if (current_nbr > lst->num)
			return (false);
		current_nbr = lst->num;
	}
	lst = head;
	return (true);
}

void	free_lst(t_dlist **lst)
{
	t_dlist	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

int	min_sum(int a, int b)
{
	int	result;

	if (a > b)
		result = b;
	else
		result = a;
	return (result);
}
