/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:25:03 by ebarbash          #+#    #+#             */
/*   Updated: 2025/02/19 20:20:33 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_nexttolast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != 0)
		lst = lst->next;
	return(lst);
}

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != 0)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*temp;

// 	temp = *lst;
// 	if (!lst || !new)
// 		return ;
// 	if (*lst == NULL)
// 		*lst = new;
// 	else
// 	{
// 		while (temp->next != NULL) // Traverse to the last node
// 			temp = temp->next;
// 		temp->next = new;  // Link the last node to new
// 	}
// }

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*temp;

// 	if (!lst || !*lst)
// 		return ;
// 	while (*lst)
// 	{
// 		temp = (*lst)->next; // storing the pointer to the next node before yeeting it
// 		del((*lst)->content);
// 		free(*lst); // freeing the node AFTER we put the pointer to the next node in temp, 
// 						// otherwise if we free the node before storing the pointer in temp
// 						// we'll lose the pointer (we free THE WHOLE)
// 		*lst = temp; // basically *lst = (*lst)->next but see the previous comment
// 	}
// 	*lst = NULL;
// }

// void	ft_lstdelone(t_list *lst, void (*del)(int))
// {
// 	del(lst->content);
// 	free(lst);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*lst_new;
// 	t_list	*temp_last;

	
// 	lst_new = NULL;
// 	if (!lst)
// 		return (NULL);
// 	while (lst)
// 	{
// 		lst_new = (t_list *)malloc(sizeof(t_list));
// 		if (lst_new == NULL)
// 			return (NULL);
// 		lst_new->content = f(lst->content);
// 		if (lst_new->content == NULL)
// 			ft_lstclear(&lst_new, del); // & basically means take the address of the address
// 										// cause the lstclear function takes a double pointer
// 										// as an argument

// 		lst = lst->next;
// 	}
// 	lst_new->next = NULL;
// 	return (lst_new);
// }



