/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:46:13 by xalves            #+#    #+#             */
/*   Updated: 2025/06/24 16:00:03 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		if (stack->binary)
			free(stack->binary);
		free(stack);
		stack = tmp;
	}
}

int	free_before_leave(t_list *a_stk, int *aux_arr)
{
	ft_free_stack(a_stk);
	free(aux_arr);
	return (ft_printf("Error\n"), 1);
}
