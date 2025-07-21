/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:17:50 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 10:49:39 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief checks for duplicate argv's
/// @param argc
/// @param argv 
/// @return 1 if there are duplicates, 0 if not
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

/// @brief checks if the string there are only digits(and +-)
/// @param str string to check 
/// @return 0 if error, 1 of not
int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
