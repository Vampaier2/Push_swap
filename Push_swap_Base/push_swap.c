/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:26:29 by xalves            #+#    #+#             */
/*   Updated: 2025/06/27 11:24:41 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/// @brief
/// @param a_stack stack A
/// @param b_stack stack B
/// @param bit_count
/// @param n_inst number of instructions
/// @return number of instructions
void	radix_sort(t_list **a, t_list **b, int bit_count)
{
	int		bit;
	int		size;
	int		i;
	t_list	*node;

	bit = 0;
	while (bit < bit_count)
	{
		size = ft_lstsize(*a);
		i = 0;
		while (i++ < size)
		{
			node = *a;
			if (node->binary[bit_count - bit - 1] == '0')
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}

void	print_list(t_list *lst)
{
	printf("List: ");
	while (lst)
	{
		printf("[%d] ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

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
	convert_to_index_and_binary(b_stack, aux_array, bigg_bit_len);
	b_stack = NULL;
	print_list(a_stack);
	free_all(a_stack, b_stack, aux_array);
	return (0);
}
