/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:56:52 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 13:54:51 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Searches content in sort_array then replaces it with idx
/// @param lst List of nodes to replace content with idx
/// @param sort_array array of sorted contents
/// @return the idx where content is found in sort_array
int	ft_get_idx(t_list *lst, int *sort_array)
{
	int	idx;

	idx = 0;
	while ((lst->content) != sort_array[idx])
		idx++;
	return (idx);
}

/// @brief gets the lenght of bit
/// @param n number to convert && get bit lenght
/// @return the lenght of the bit
int	get_bit_length(int n)
{
	int	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n > 0)
	{
		n >>= 1;
		length++;
	}
	return (length);
}

/// @brief finds the node with the smallest content
/// @param stack stack/list to find the content
/// @return position of node with smallest content
int	get_min_content(t_list *stack)
{
	int	min;
	int	pos;
	int	i;

	min = stack->content;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
