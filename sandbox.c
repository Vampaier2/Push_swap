/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:05:09 by xalves            #+#    #+#             */
/*   Updated: 2025/06/10 17:23:22 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_last_binary_digit(int num)
{
	return (num & 1); // Bitwise AND with 1 extracts the last binary digit
}

#include <stdio.h>

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

int	main(void)
{
	int	num[] = {7, 13, 2, 56, 124, 5, 82, 1};
	int	i;

	i = 0;
	int size = sizeof(num) / sizeof(num[0]); // Calculate array size (6)

	printf("\nSize -> |%d|\n", size);
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
}
