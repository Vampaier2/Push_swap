/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:05:09 by xalves            #+#    #+#             */
/*   Updated: 2025/06/17 17:42:02 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/* int	get_last_binary_digit(int num)
{
	return (num & 1); // Bitwise AND with 1 extracts the last binary digit
} */
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

int get_bit_length(int n)
{
	int length;

	length = 0;
	while (n > 0)
	{
		n >>= 1;
		length++;
	}
	return (length == 0) ? 1 : length; // handle n == 0
}

char *int_to_binary(int n, int length)
{
	char *binary;
	int i;

	binary = malloc(length + 1);
	if (!binary)
		return NULL;
	binary[length] = '\0';

	i = 0;
	while (i < length)
	{
		if (n & (1 << (length - 1 - i)))
			binary[i] = '1';
		else
			binary[i] = '0';
		i++;
	}
	return binary;
}

int	ft_get_idx(t_list *lst, int *sort_array)
{
	int	idx;

	idx = 0;
	while ((lst->content) != sort_array[idx])
		idx++;
	return (idx);
}

void	index_and_convert_list(t_list *lst, int *sorted_array, int max_index)
{
	int	bit_length = get_bit_length(max_index);

	printf("\n\nIndexed List:\n");
	while (lst)
	{
		lst->content = ft_get_idx(lst, sorted_array);
		lst->binary = int_to_binary(lst->content, bit_length);
		printf("[%d]->[%s]\n", lst->content, lst->binary);
		lst = lst->next;
	}
	printf("\nBigger idx = %d\n\n", max_index);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return 0;
		stack = stack->next;
	}
	return 1;
}

void radix_sort(t_list **a_stack, t_list **b_stack, int max_index)
{
	int bit = 0;
	int bit_count = get_bit_length(max_index);

	while (bit < bit_count)
	{
		int size = ft_lstsize(*a_stack);
		int i = 0;

		while (i < size)
		{
			if ((*a_stack)->binary[bit_count - 1 - bit] == '0')
			{
				ft_push(b_stack, a_stack); // push to B
				printf("\npush");
			}
			else
			{
				ft_rlst(a_stack); // rotate A
				printf("\nrotate");
			}
			if (is_sorted(*a_stack))
				break;
			i++;
		}
		// Push all from B back to A
		while (*b_stack)
			ft_push(a_stack, b_stack);
		bit++;
	}
}


int	main(int argc, char const *argv[])
{
	int		i;
	long	content_aux;
	t_list	*a_stack;
	t_list	*b_stack;
	int		*aux_array;
	int		M_idx;

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
		if (!ft_str_isdigit((char *) argv[i]))
			return (printf("Invalid Number!!!"), 0);
		content_aux = ft_atoi(argv[i]);
		if (content_aux == LONG_MAX)
			return (printf("Invalid Number!!!"), 0);
		ft_lstadd_back(&a_stack, ft_lstnew(content_aux));
		aux_array[i - 1] = content_aux;
		i++;
	}
	M_idx = ft_lstsize(a_stack) - 1;
	print_list(a_stack);
	printf("\n");
	// Sort Aray
	printf("Sort List:");
	ft_sort_int_tab(aux_array, argc - 1);
	i = 1;
	while (i < argc)
	{
		printf(" [%d] ", aux_array[i - 1]);
		i++;
	}
	// Find and Replace
	printf("\n\n");
	// Find and Replace
	printf("\n\n");
	t_list *tmp = a_stack; // temp pointer to traverse list
	while (tmp)
	{
		tmp->content = ft_get_idx(tmp, aux_array);
		tmp->binary = int_to_binary(tmp->content, get_bit_length(M_idx));
		printf("\n[%d]->[%s]", tmp->content, tmp->binary);
		tmp = tmp->next;
	}
	// Push Swaping
	radix_sort(&a_stack, &b_stack, M_idx);
	print_list(a_stack);
	return (0);
}
