/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergei_pilman <sergei_pilman@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:55:54 by ebarbash          #+#    #+#             */
/*   Updated: 2025/03/24 01:17:59 by sergei_pilm      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	reverse_rotate_lst(stack_a);
	reverse_rotate_lst(stack_b);
	ft_printf("rrr\n");
}

void	swap_lst(t_dlist *head)
{
	t_dlist	*first;
	t_dlist	*second;
	int		temp;

	if (!head || !head->next)
		return ;
	first = head;
	second = head->next;
	temp = first->num;
	first->num = second->num;
	second->num = temp;
}

void	push_lst(t_dlist **head_a, t_dlist **head_b)
{
	t_dlist	*temp_next_ptr;

	if (!*head_a)
		return ;
	temp_next_ptr = (*head_a)->next;
	if (*head_b)
		(*head_b)->prev = *head_a;
	(*head_a)->next = *head_b;
	*head_b = *head_a;
	*head_a = temp_next_ptr;
}

void	rotate_lst(t_dlist **head)
{
	t_dlist	*new_head;
	t_dlist	*temp_old_head;
	t_dlist	*last;

	if (!*head || !(*head)->next)
		return ;
	temp_old_head = *head;
	new_head = (*head)->next;
	new_head->prev = NULL;
	last = ft_dlstlast(*head);
	last->next = temp_old_head;
	(*head)->prev = last;
	temp_old_head->next = NULL;
	*head = new_head;
}

void	reverse_rotate_lst(t_dlist **head)
{
	t_dlist	*new_last;
	t_dlist	*last;

	if (!*head || !(*head)->next)
		return ;
	new_last = ft_lst_nexttolast(*head);
	last = ft_dlstlast(*head);
	new_last->next = NULL;
	last->next = *head;
	(*head)->prev = last;
	last->prev = NULL;
	*head = last;
}
