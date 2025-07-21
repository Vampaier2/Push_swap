/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:06:34 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 11:30:31 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Sorts/orders an array of ints
/// @param tab array of ints
/// @param size size of the array
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	size = size - 1;
	while (i < size)
	{
		while (j < size + 1)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
		j = i;
	}
}

/// @brief swaps the top 2 nodes from B
/// @param stack_b 
void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_putstr_fd("sb\n", 1);
}
