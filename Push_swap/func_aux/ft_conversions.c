/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:42:16 by xalves            #+#    #+#             */
/*   Updated: 2025/06/27 11:32:14 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

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

char	*int_to_binary(int num, int bit_len)
{
	char	*binary;
	int		i;

	binary = malloc(bit_len + 1);
	if (!binary)
		return (NULL);
	i = bit_len;
	binary[i] = '\0';
	while (i-- > 0)
	{
		if ((num & 1) == 1)
			binary[i] = '1';
		else
			binary[i] = '0';
		num >>= 1;
	}
	return (binary);
}

void	convert_to_index_and_binary(t_list *stack, int *aux_arr, int bit_ln)
{
	while (stack)
	{
		stack->content = ft_get_idx(stack, aux_arr);
		free(stack->binary);
		stack->binary = int_to_binary(stack->content, bit_ln);
		stack = stack->next;
	}
}
