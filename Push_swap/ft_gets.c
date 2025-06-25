/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:56:52 by xalves            #+#    #+#             */
/*   Updated: 2025/06/25 12:40:55 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_idx(t_list *lst, int *sort_array)
{
	int	idx;

	idx = 0;
	while ((lst->content) != sort_array[idx])
		idx++;
	return (idx);
}

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

int	get_min_pos(t_list *stack)
{
	int	min;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	min = stack->content;
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

void	get_min_to_top(t_list **a, int min_pos)
{
	while (min_pos-- > 0)
		ra(a);
}
