/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:26:29 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 14:35:43 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief populates the stack with the argv's
/// @param argc
/// @param argv
/// @param a_stk stack_a
/// @param aux_a auxiliar stack
/// @return 0 if nothing wrong, 1 if error
int	populate_stk(int argc, char const *argv[], t_list **a_stk, int **aux_a)
{
	int		i;
	long	content_aux;

	i = 1;
	content_aux = 0;
	if (ft_check_dupes(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	*aux_a = malloc((argc - 1) * sizeof(int));
	if (!*aux_a)
		return (ft_putstr_fd("Error\n", 2), 1);
	while (i < argc)
	{
		if (!ft_str_isdigit((char *)argv[i]))
			return (free_before_leave(*a_stk, *aux_a), 1);
		content_aux = ft_atoi(argv[i]);
		if (content_aux == LONG_MAX)
			return (free_before_leave(*a_stk, *aux_a), 1);
		ft_lstadd_back(a_stk, ft_lstnew(content_aux));
		(*aux_a)[i - 1] = content_aux;
		i++;
	}
	return (0);
}

/// @brief Ngl isto foi so para poupar linhas
/// @param a_stack
/// @param aux_arr
/// @param argc
/// @param blen
void	prepping_for_radix(t_list **a_stack, int *aux_arr, int argc, int blen)
{
	ft_sort_int_tab(aux_arr, argc - 1);
    convert_to_index_and_binary(*a_stack, aux_arr, blen);
}

/// @brief  sorts stack A thru Binary Radix method
/// @param a_stack stack A
/// @param b_stack stack B
/// @param bit_len lenght of biggest bit
/// @param n_inst number of instructions
/// @return number of instructions
void	radix_sort(t_list **a, t_list **b, int bit_len)
{
	int		bit;
	int		size;
	int		i;
	t_list	*node;

	bit = 0;
	while (bit < bit_len)
	{
		size = ft_lstsize(*a);
		i = 0;
		while (i++ < size)
		{
			node = *a;
			if (!(node->content & (1 << bit)))
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}

int	main(int argc, char const *argv[])
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		*aux_array;
	int		bigg_bit_len;
	int		size;

	a_stack = NULL;
	b_stack = NULL;
	aux_array = NULL;
	if (argc <= 1)
		return (1);
	if (populate_stk(argc, argv, &a_stack, &aux_array))
		return (1);
	if (is_stack_sorted(a_stack))
		return (0);
	size = ft_lstsize(a_stack);
	if (size <= 5)
		small_sort(&a_stack, &b_stack, size);
	else
	{
		bigg_bit_len = get_bit_length(size - 1);
        prepping_for_radix(&a_stack, aux_array, argc, bigg_bit_len);
		radix_sort(&a_stack, &b_stack, bigg_bit_len);
	}
	return (free_all(a_stack, b_stack, aux_array), 0);
}
