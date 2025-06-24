/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:52:27 by xalves            #+#    #+#             */
/*   Updated: 2025/06/24 16:20:56 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "func_aux/func_aux.h"
# include "ft_printf/ft_printf.h"

// ft_free_func.c
void	ft_free_stack(t_list *stack);
int		free_before_leave(t_list *a_stk, int *aux_arr);

// ft_gets.c
int		ft_get_idx(t_list *lst, int *sort_array);
int		get_bit_length(int n);

// ft_parcing.c
int		ft_check_dupes(int argc, char const *argv[]);
int		ft_str_isdigit(char *str);

// ft_push_rotate.c
void	ft_push(t_list **dst, t_list **src);
void	push_all_b(t_list **dst, t_list **src);
void	ft_rlst(t_list **lst);

// ft_sort_int_tab.c
void	ft_sort_int_tab(int *tab, int size);

// push_swap.c
void	ft_push_or_rotate(t_list **a_st, t_list **b_st, int bit, int bit_count);
int		populate_stk(int argc, char const *argv[], t_list **a_stk, int **aux_a);
void	radix_sort(t_list **a_stack, t_list **b_stack, int bit_count);

#endif
