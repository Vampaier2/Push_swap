/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aux.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:52:27 by xalves            #+#    #+#             */
/*   Updated: 2025/06/27 11:32:37 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_AUX_H
# define FUNC_AUX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
	char			*binary;
}	t_list;

// ft_calloc.c
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// ft_conversions.c
long	ft_atoi(const char *nptr);
char	*int_to_binary(int n, int length);
void	convert_to_index_and_binary(t_list *stack, int *aux_arr, int bit_ln);

// ft_lst_func.c
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
int		ft_lstsize(t_list *lst);
void	ft_putstr_fd(char *s, int fd);

//is_stack_sorted.c
int		is_stack_sorted(t_list *stack);

#endif
