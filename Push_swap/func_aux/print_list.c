/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:54:29 by xalves            #+#    #+#             */
/*   Updated: 2025/06/18 15:36:05 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_aux.h"

void	print_list(t_list *lst)
{
	printf("\nO List: ");
	while (lst)
	{
		printf("[%d] ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}
