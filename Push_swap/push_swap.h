/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:52:27 by xalves            #+#    #+#             */
/*   Updated: 2025/06/25 14:33:05 by xalves           ###   ########.fr       */
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
int		get_min_pos(t_list *stack);
void	get_min_to_top(t_list **a, int min_pos);

// ft_parcing.c
int		ft_check_dupes(int argc, char const *argv[]);
int		ft_str_isdigit(char *str);

// ft_push_rotate.c
void	ft_push(t_list **dst, t_list **src);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	sa(t_list **a);

// ft_sort_int_tab.c
void	ft_sort_int_tab(int *tab, int size);
void	small_sort(t_list **a, t_list **b, int size);
void	sort_three(t_list **a);

// push_swap.c
int		populate_stk(int argc, char const *argv[], t_list **a_stk, int **aux_a);
void	radix_sort(t_list **a, t_list **b, int bit_count);

#endif
