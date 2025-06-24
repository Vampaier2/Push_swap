/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:26:29 by xalves            #+#    #+#             */
/*   Updated: 2025/06/24 17:42:09 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_or_rotate(t_list **a_st, t_list **b_st, int bit, int bit_count)
{
	if ((*a_st)->binary[bit_count - 1 - bit] == '0')
	{
		ft_push(b_st, a_st);
		printf("pb\n");
	}
	else
	{
		ft_rlst(a_st);
		printf("ra\n");
	}
}

int	populate_stk(int argc, char const *argv[], t_list **a_stk, int **aux_a)
{
	int		i;
	long	content_aux;

	i = 1;
	content_aux = 0;
	if (ft_check_dupes(argc, argv))
		return (printf("Error\n"), 1);
	*aux_a = malloc((argc - 1) * sizeof(int));
	if (!*aux_a)
		return (printf("Error\n"), 1);
	while (i < argc)
	{
		if (!ft_str_isdigit((char *)argv[i]))
			return (free_before_leave(*a_stk, *aux_a), 1);
		content_aux = ft_atoi(argv[i]);  // <-- You forgot this line!
		if (content_aux == LONG_MAX)
			return (free_before_leave(*a_stk, *aux_a), 1);
		ft_lstadd_back(a_stk, ft_lstnew(content_aux));
		(*aux_a)[i - 1] = content_aux;
		i++;
	}
	return (0);
}

/// @brief
/// @param a_stack stack A
/// @param b_stack stack B
/// @param bit_count
/// @param n_inst number of instructions
/// @return number of instructions
void	radix_sort(t_list **a_stack, t_list **b_stack, int bit_count)
{
	int	bit;
	int	size;
	int	i;

	bit = 0;
	if (!a_stack || !*a_stack || !(*a_stack)->binary || !(*a_stack)->next)
		return ;
	while (bit < bit_count)
	{
		size = ft_lstsize(*a_stack);
		i = 0;
		while (i < size)
		{
			if (is_stack_sorted(*a_stack))
				break ;
			ft_push_or_rotate(a_stack, b_stack, bit, bit_count);
			i++;
		}
		if (!is_stack_sorted(*a_stack))
			push_all_b(a_stack, b_stack);
		bit++;
	}
}

/// @brief
/// @param argc number of arguments
/// @param argv
/// @return
int	main(int argc, char const *argv[])
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		*aux_array;
	int		bigg_bit_len;

	a_stack = NULL;
	b_stack = NULL;
	if (argc <= 1)
		return (0);
	if (populate_stk(argc, argv, &a_stack, &aux_array))
		return (1);
	bigg_bit_len = get_bit_length(ft_lstsize(a_stack) - 1);
	ft_sort_int_tab(aux_array, argc - 1);
	b_stack = a_stack;
	while (b_stack)
	{
		b_stack->content = ft_get_idx(b_stack, aux_array);
		b_stack->binary = int_to_binary(b_stack->content, bigg_bit_len);
		b_stack = b_stack->next;
	}
	b_stack = NULL;
	radix_sort(&a_stack, &b_stack, bigg_bit_len);
	free(aux_array);
	ft_free_stack(a_stack);
	return (0);
}
