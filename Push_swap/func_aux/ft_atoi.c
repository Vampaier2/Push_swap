/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:42:16 by xalves            #+#    #+#             */
/*   Updated: 2025/06/18 15:04:45 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_aux.h"

long	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;
	long	result;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	result = sign * res;
	if (result > INT_MAX || result < INT_MIN)
		return (LONG_MAX);
	return (result);
}
