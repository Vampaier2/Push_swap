/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search_and_replace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:48:59 by xalves            #+#    #+#             */
/*   Updated: 2025/06/13 15:54:09 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_search_and_replace(t_list *lst, int content)
{
	int	idx;

	idx = 0;
	while ((lst->content) != content)
	{
		lst = lst->next;
		idx++;
	}
	return (idx);
}
