/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aux.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:52:27 by xalves            #+#    #+#             */
/*   Updated: 2025/06/18 15:59:12 by xalves           ###   ########.fr       */
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

long	ft_atoi(const char *nptr);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_str_isdigit(char *str);
char	*int_to_binary(int n, int length);
int		is_stack_sorted(t_list *stack);
void	print_list(t_list *lst);

#endif
