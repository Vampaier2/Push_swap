/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:06:34 by xalves            #+#    #+#             */
/*   Updated: 2025/07/01 15:35:10 by xalves           ###   ########.fr       */
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

void	push_two_smallest_to_b(t_list **a, t_list **b)
{
	int	min1_pos;
	int	min2_pos;

	min1_pos = find_min(*a);
	bring_to_top(a, min1_pos);
	pb(a, b); // Push 1st smallest to B
	min2_pos = find_min(*a);
	bring_to_top(a, min2_pos);
	pb(a, b); // Push 2nd smallest to B
}

int	find_min(t_list *stack)
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

void	bring_to_top(t_list **stack, int pos)
{
	int	size;

	size = ft_lstsize(*stack);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack); // Rotate forward
	else
		while (pos++ < size)
			rra(stack); // Rotate backward
}

void	sb(t_list **b)
{
    t_list *first;
	t_list *second;
	if (!*b || !(*b)->next) // If stack is empty or has only one element
		return ;             // Do nothing (no swap possible)
	first = *b;
	second = first->next;
	// Swap the first two nodes
	first->next = second->next;
	second->next = first;
	*b = second; // Update stack head to point to the new top (second)
}