/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:49:34 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 13:55:40 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief checks if the stack/list is sorted
/// @param stack stack to check
/// @return 1 if sorted, 0 if not
int	is_stack_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
