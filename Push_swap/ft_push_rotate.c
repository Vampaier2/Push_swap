/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:52:44 by xalves            #+#    #+#             */
/*   Updated: 2025/06/24 17:40:14 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Pushes from src->dest || 2'nd to 1'st variable
/// @param dst Where the node from src is going
/// @param src Where node comes from
void	ft_push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(dst, tmp);
}

void	push_all_b(t_list **dst, t_list **src)
{
	while (*src)
	{
		ft_push(dst, src);
		printf("pa\n");
	}
}

/// @brief rotates the designated list
/// @param lst list to be rotted
void	ft_rlst(t_list **lst)
{
	t_list	*first;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	*lst = first->next;
	(*lst)->prev = NULL;
	first->next = NULL;
	first->prev = NULL;
	ft_lstadd_back(lst, first);
}
