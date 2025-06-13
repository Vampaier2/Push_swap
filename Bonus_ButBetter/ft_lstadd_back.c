/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:16:19 by xalves            #+#    #+#             */
/*   Updated: 2025/06/11 15:44:52 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}
/*
void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	printf("\n");
}
int	main(void)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	// Create and add nodes
	ft_lstadd_back(&head, ft_lstnew("Node 1"));
	ft_lstadd_back(&head, ft_lstnew("Node 2"));
	ft_lstadd_back(&head, ft_lstnew("Node 3"));
	ft_lstadd_back(&head, ft_lstnew("Node 4"));
	// Print list
	printf("Linked list contents:\n");
	print_list(head);
	// Free list memory
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}
*/
