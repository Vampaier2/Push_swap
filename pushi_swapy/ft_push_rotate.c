/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:52:44 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 10:55:27 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief pushes from A to B
/// @param stack_a 
/// @param stack_b 
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	tmp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = tmp;
	tmp->prev = NULL;
	*stack_b = tmp;
	ft_putstr_fd("pb\n", 1);
}

/// @brief pushes from B to A
/// @param stack_a 
/// @param stack_b 
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

/// @brief rotates stack A up by one
/// @param stack_a 
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
	(*stack_a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	ft_putstr_fd("ra\n", 1);
}

/// @brief rotates stack A down by one
/// @param stack_a 
void	rra(t_list **stack_a)
{
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack_a;
	last->prev = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	ft_putstr_fd("rra\n", 1);
}

/// @brief swaps the top 2 nodes from A
/// @param stack_a 
void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	ft_putstr_fd("sa\n", 1);
}
