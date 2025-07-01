/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:52:44 by xalves            #+#    #+#             */
/*   Updated: 2025/07/01 13:13:17 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Pushes from src->dest || 2'nd to 1'st variable
/// @param dst Where the node from src is going
/// @param src Where node comes from

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("ra\n", 1);
}
/// @brief
/// @param a
void	rra(t_list **a)
{
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	*a = last;
	ft_putstr_fd("rra\n", 1);
}
void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*a = second;
	ft_putstr_fd("sa\n", 1);
}
