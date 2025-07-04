/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:52:27 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 11:29:24 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "func_aux/func_aux.h"

// ft_free_func.c
void	ft_free_stack(t_list *stack);
int		free_before_leave(t_list *a_stk, int *aux_arr);
void	free_all(t_list *a_stack, t_list *b_stack, int *aux_array);

// ft_gets.c
int		ft_get_idx(t_list *lst, int *sort_array);
int		get_bit_length(int n);
int		get_min_content(t_list *stack);

// ft_parcing.c
int		ft_check_dupes(int argc, char const *argv[]);
int		ft_str_isdigit(char *str);

// ft_push_rotate.c
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rra(t_list **a);
void	sa(t_list **a);

// ft_sorts.c
void	ft_sort_int_tab(int *tab, int size);
void	sb(t_list **b);

// push_swap.c
int		populate_stk(int argc, char const *argv[], t_list **a_stk, int **aux_a);
void	radix_sort(t_list **a, t_list **b, int bit_count);

// smal_radix.c
void	small_sort(t_list **a, t_list **b, int size);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);

#endif
