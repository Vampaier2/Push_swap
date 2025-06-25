/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:17:50 by xalves            #+#    #+#             */
/*   Updated: 2025/06/24 15:54:02 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dupes(int argc, char const *argv[])
{
	int		i;
	int		j;
	long	val_i;
	long	val_j;

	i = 1;
	while (i < argc)
	{
		val_i = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			val_j = ft_atoi(argv[j]);
			if (val_i == val_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else if (str[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}
