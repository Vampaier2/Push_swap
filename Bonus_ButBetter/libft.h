/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:52:27 by xalves            #+#    #+#             */
/*   Updated: 2025/06/13 12:29:27 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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
	int				binary;
}	t_list;

void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	print_list(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
#endif
