/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:03:57 by xalves            #+#    #+#             */
/*   Updated: 2025/06/11 12:49:17 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !lst)
		return ;
	if ((*lst)->prev)
		((*lst)->prev)->next = NULL;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
/*
void	del_content(void *content)
{
	free(content);
}

#include <string.h>

int	main(void)
{
	t_list	*head;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(strdup("Node 1")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Node 2")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Node 3")));
	printf("Before clear:\n");
	print_list(head);
	ft_lstclear(&head, del_content);
	printf("After clear:\n");
	print_list(head);
	return (0);
}*/
