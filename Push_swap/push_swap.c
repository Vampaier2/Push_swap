/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:26:29 by xalves            #+#    #+#             */
/*   Updated: 2025/06/23 17:46:13 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Radix Sort (base 2)
int	ft_get_idx(t_list *lst, int *sort_array)
{
	int	idx;

	idx = 0;
	while ((lst->content) != sort_array[idx])
		idx++;
	return (idx);
}

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

void	push_all_b(t_list **a_stack, t_list **b_stack)
{
	while (*b_stack)
	{
		ft_push(a_stack, b_stack);
		printf("pa\n");
	}
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
	t_list	*tmp;
	int		i;
	long	content_aux;
	int		*aux_array;
	int		bigg_bit_len;

	i = 1;
	a_stack = NULL;
	b_stack = NULL;
	// Populate Array
	aux_array = malloc((argc - 1) * sizeof(int));
	if (!aux_array)
		return (printf("Memory allocation failed!\n"), 1);
	while (i < argc)
	{
		// If it detects any non number on input
		if (!ft_str_isdigit((char *)argv[i]))
			return (printf("Invalid Number!!!"), 0);
		content_aux = ft_atoi(argv[i]);
		if (content_aux == LONG_MAX)
			return (printf("Invalid Number!!!"), 0);
		ft_lstadd_back(&a_stack, ft_lstnew(content_aux));
		aux_array[i - 1] = content_aux;
		i++;
	}
	bigg_bit_len = get_bit_length(ft_lstsize(a_stack) - 1);
	//print_list(a_stack);
	// Sort Aray
	//printf("\nS List: ");
	ft_sort_int_tab(aux_array, argc - 1);
	i = 1;
	/* while (i < argc)
	{
		printf("[%d] ", aux_array[i - 1]);
		i++;
	} */
	// Find and Replace
	//printf("\n---------------------------------");
	//print_list(a_stack);
	tmp = a_stack; // temp pointer to traverse list
	//printf("\nI List: ");
	while (tmp)
	{
		tmp->content = ft_get_idx(tmp, aux_array);
		tmp->binary = int_to_binary(tmp->content, bigg_bit_len);
		//printf("\n[%d]->[%s]", tmp->content, tmp->binary);
		//printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	// Push Swaping
	radix_sort(&a_stack, &b_stack, bigg_bit_len);
	/* printf("\n\n\n!!! Stack Sorted !!!\n");
	print_list(a_stack);
	printf("\nNumber of Instructions-> %d", i); */
	return (0);
}
