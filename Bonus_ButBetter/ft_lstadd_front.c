/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:05 by xalves            #+#    #+#             */
/*   Updated: 2025/06/11 15:45:00 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node->next = *lst;
	new_node->prev = NULL;
	if (*lst)
		(*lst)->prev = new_node;
	*lst = new_node;
}
/*
My function flow:

	Before: NULL <- [A] <-> [B] <-> [C] -> NULL

	new_node->next = *lst;
	→ [D].next = [A]

	new_node->prev = NULL;
	→ [D].prev = NULL (it's the new_node head)

	(*lst)->prev = new_node; || -> sets 'old head node' prev to 'new_node node'
	→ [A].prev = [D]

	*lst = new_node;
	→ Head pointer now points to [D]

	After: NULL <- [D] <-> [A] <-> [B] <-> [C] -> NULL
*/
/*
void	print_list(t_list *head)
{
	printf("List (forward): ");
	while (head)
	{
		printf("%s ", (char *)head->content);
		head = head->next;
	}
	printf("\n");
}
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	head = NULL;
	node1 = ft_lstnew("Steel");
	node2 = ft_lstnew(" && ");
	node3 = ft_lstnew("Flint");
	ft_lstadd_front(&head, node1); // List: Steel
	ft_lstadd_front(&head, node2); // List: && -> Steel
	ft_lstadd_front(&head, node3); // List: Flint -> &&
	print_list(head);
	// Optional: free memory
	free(node1);
	free(node2);
	return (0);
}
 */
