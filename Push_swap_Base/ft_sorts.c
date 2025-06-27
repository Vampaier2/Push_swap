/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:06:34 by xalves            #+#    #+#             */
/*   Updated: 2025/06/26 15:35:34 by xalves           ###   ########.fr       */
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

void	small_sort(t_list **a, t_list **b, int size)
{
	int	min_pos;

	if (size == 2 && (*a)->content > (*a)->next->content)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
	{
		while (ft_lstsize(*a) > 3)
		{
			min_pos = get_min_pos(*a);
			while (min_pos-- > 0)
				ra(a);
			pb(a, b);
		}
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}

void	sort_three(t_list **a)
{
	int	mid;
	int	bot;

	mid = (*a)->next->content;
	bot = (*a)->next->next->content;
	if ((*a)->content > mid && mid < bot && bot > (*a)->content)
		sa(a);
	else if ((*a)->content > mid && mid > bot)
	{
		sa(a);
		ra(a);
		sa(a);
	}
	else if ((*a)->content > mid && mid < bot && (*a)->content > bot)
		ra(a);
	else if ((*a)->content < mid && mid > bot && bot > (*a)->content)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->content < mid && mid > bot && (*a)->content > bot)
	{
		ra(a);
		sa(a);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	push_two_smallest(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	push_two_smallest(t_list **a, t_list **b)
{
	int	min_pos;

	// First smallest
	min_pos = get_min_pos(*a);
	while (min_pos-- > 0)
		ra(a);
	pb(a, b);
	// Second smallest (recalculate position in modified stack)
	min_pos = get_min_pos(*a);
	while (min_pos-- > 0)
		ra(a);
	pb(a, b);
}
