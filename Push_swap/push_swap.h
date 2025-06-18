/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:52:27 by xalves            #+#    #+#             */
/*   Updated: 2025/06/18 16:02:45 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "func_aux/func_aux.h"

void	ft_push(t_list **dst, t_list **src);
void	ft_rlst(t_list **lst);
void	ft_sort_int_tab(int *tab, int size);
int		get_bit_length(int n);

int		ft_get_idx(t_list *lst, int *sort_array);
void	ft_push_or_rotate(t_list **a_st, t_list **b_st, int bit, int bit_count);
int		radix_sort(t_list **a_stack, t_list **b_stack, int bit_count);

#endif
