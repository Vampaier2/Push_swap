/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:32:12 by xalves            #+#    #+#             */
/*   Updated: 2025/06/18 15:04:15 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_aux.h"

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
