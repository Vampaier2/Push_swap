/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:56:52 by xalves            #+#    #+#             */
/*   Updated: 2025/06/24 15:46:56 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Radix Sort (base 2)
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
