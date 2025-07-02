/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:06:34 by xalves            #+#    #+#             */
/*   Updated: 2025/07/02 14:22:04 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	bring_to_top(t_list **stack, int pos)
{
	int	size;

	size = ft_lstsize(*stack);
	if (pos <= size / 2)
	{
		// Element is in first half - rotate forward
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		// Element is in second half - rotate backward
		while (pos++ < size - 1)
			rra(stack);
	}
}

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (!*b || !(*b)->next) // If stack is empty or has only one element
		return ;             // Do nothing (no swap possible)
	first = *b;
	second = first->next;
	// Swap the first two nodes
	first->next = second->next;
	second->next = first;
	*b = second; // Update stack head to point to the new top (second)
	ft_putstr_fd("sb\n", 1);
}
