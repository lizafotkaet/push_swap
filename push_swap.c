/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarbash <ebarbash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:21:02 by ebarbash          #+#    #+#             */
/*   Updated: 2025/02/19 20:42:43 by ebarbash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_lst(t_list *head)
{
	t_list	*first;
	t_list	*second;
	int		temp;
	
	if (!head || !head->next)
		return ;
	first = head;
	second = head->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	push_lst(t_list **head_a, t_list **head_b)
{
	t_list	*temp_ptr;
	
	if (!head_b) // !!!!!!!!????? what if there's only one element in b
		return ;
	temp_ptr = (*head_b)->next; // pointer to now second element of stack b (to be the first element of stack b)
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	*head_b = temp_ptr;
}

void	rotate_lst(t_list **head)
{
	t_list	*new_head;
	t_list	*temp_old_head; 
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	temp_old_head = *head;
	new_head = (*head)->next; // the current second element of the stack eventually becomes the first element, i.e. the new head
	last = ft_lstlast(*head); // currently last == NULL, we need it to point to the OG head which is stored in temp_head now
	last->next = temp_old_head; // now the last element points not to nothing but to the old head (cause it's the last element now)
	temp_old_head->next = NULL; // the old head is now the last element so it points to nothing
	*head = new_head; // update the OG list head
}

void	reverse_rotate_lst(t_list **head)
{
	t_list	*next_to_last;
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	next_to_last = ft_lst_nexttolast(*head); // first we get to the second to last node
	last = ft_lstlast(*head); // then to the last node
	next_to_last->next = NULL; // the second to last node now puts to nothing (cause bc of reverse rotating it's the last element now)
	last->next = *head; // the pointer of the last element initially was NULL (cause it's last, points to nothing) now it points to the current head (the initial first node), basically we put the OG head pointer "inside" the first node and it points to the new second element now, not first
	*head = last; // the head pointer points to the last element now cause we moved it up and it's not last but first now YAAAAAAAAAY
}

t_list	*test_put_lst_a()
{
	t_list	*stack_a;
	t_list	*head_a;

	stack_a = ft_lstnew(42);
	head_a = stack_a;
	stack_a->next = ft_lstnew(3);
	stack_a->next->next = ft_lstnew(7);
	stack_a->next->next->next = ft_lstnew(-9);
	return (head_a);
}

t_list	*test_put_lst_b()
{
	t_list	*stack_b;
	t_list	*head_b;

	stack_b = ft_lstnew(4);
	head_b = stack_b;
	stack_b->next = ft_lstnew(1);
	stack_b->next->next = ft_lstnew(0); 
	return (stack_b);
}

int	main(void)
{
	t_list	*stack_a;
	t_list	*head_a;
	t_list	*stack_b;
	t_list	*head_b;
	// char *stack_a = "4 54 55 0 -9";
	
	stack_a = test_put_lst_a();
	stack_b = test_put_lst_b();
	head_a = stack_a;
	head_b = stack_b;

	printf("Stack a before:\n");
	while(stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	stack_a = head_a;
	
	// printf("Stack b before:\n");
	// while(stack_b)
	// {
	// 	printf("%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// }
	// stack_b = head_b;

	// push_lst(&stack_a, &stack_b);

	// printf("Stack a after:\n");
	// while(stack_a)
	// {
	// 	printf("%d\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	// printf("Stack b after:\n");
	// while(stack_b)
	// {
	// 	printf("%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// }

	
	reverse_rotate_lst(&stack_a);
	printf("Stack a after reverse rotate:\n");
	while(stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}
/* */