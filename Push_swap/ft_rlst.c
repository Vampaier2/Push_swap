/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:27:40 by xalves            #+#    #+#             */
/*   Updated: 2025/06/18 12:43:07 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
---move head one down---
	*lst = first->next;
	(*lst)->prev = NULL;
---// get last node---
	last = *lst;
	while (last->next)
		last = last->next;
---first node to the end---
last->next = first;
	first->prev = last;
	first->next = NULL;
*/
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
