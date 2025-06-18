/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:42:56 by xalves            #+#    #+#             */
/*   Updated: 2025/06/18 15:04:18 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_aux.h"

char	*int_to_binary(int n, int length)
{
	char	*binary;
	int		i;

	binary = malloc(length + 1);
	if (!binary)
		return (NULL);
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
	return (binary);
}
