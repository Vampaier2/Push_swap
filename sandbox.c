/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:05:09 by xalves            #+#    #+#             */
/*   Updated: 2025/06/13 15:13:30 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char const *argv[])
{
	int		i;
	long	content_aux;
	t_list	*og_list;
	int		*aux_array;

	i = 1;
	og_list = NULL;
	aux_array = malloc((argc - 1) * sizeof(int));
	if (!aux_array)
		return (printf("Memory allocation failed!\n"), 1);
	while (i < argc)
	{
		content_aux = ft_atoi(argv[i]);
		if (content_aux == LONG_MAX)
			return (printf("Invalid Number!!!"), 0);
		ft_lstadd_back(&og_list, ft_lstnew(content_aux));
		aux_array[i - 1] = content_aux;
		i++;
	}
	print_list(og_list);
	printf("\n\n");
	printf("Sort List:\n");
	ft_sort_int_tab(aux_array, argc - 1);
	i = 1;
	while (i < argc)
	{
		printf("[%d]", aux_array[i - 1]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	t_list	*head;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew());
	ft_lstadd_back(&head, ft_lstnew());
	ft_lstadd_back(&head, ft_lstnew());
	printf("Before clear:\n");
	print_list(head);
	ft_lstclear(&head);
	printf("After clear:\n");
	print_list(head);
	return (0);
} */
/* int	main(void)
{
	int	num[] = {23, 4, 15, 8, 42, 16, 7, 0, 3, 31};
	int	i;

	i = 0;
	int size = sizeof(num) / sizeof(num[0]); // Calculate array size (6)

	printf("\nSize -> |%d|\n", size);
	while (i < size)
	{
		printf("%d|", num[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_sort_int_tab(num, size);
	while (i < size)
	{
		printf("%d|", num[i]);
		i++;
	}
	printf("\n\n");
	i=0;
	while (i < size)
	{
		if (get_last_binary_digit(num[i]) == 0)
			printf("Push to B (pb) |%d|->|%d|\n", num[i],
				get_last_binary_digit(num[i]));
		else
			printf("Rotate A (ra) |%d|->|%d|\n", num[i],
				get_last_binary_digit(num[i]));
		i++;
	}
	return (0);
} */
