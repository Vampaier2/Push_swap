/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smal_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:39:15 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 13:53:16 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first > second && second < third && first < third)
		sa(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_list **a, t_list **b)
{
	int	min_pos;

	min_pos = get_min_content(*a);
	if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	int	min_pos;

	while (ft_lstsize(*a) > 3)
	{
		min_pos = get_min_content(*a);
		if (min_pos <= ft_lstsize(*a) / 2)
			while (min_pos-- > 0)
				ra(a);
		else
			while (min_pos++ < ft_lstsize(*a))
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	if ((*b)->content < (*b)->next->content)
		sb(b);
	pa(a, b);
	pa(a, b);
}
