/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:38:17 by xalves            #+#    #+#             */
/*   Updated: 2025/07/04 15:02:30 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief creates new node
/// @param content content to be given new node
/// @return returns the created node
t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node ->content = content;
	new_node ->next = NULL;
	new_node ->prev = NULL;
	new_node ->binary = NULL;
	return (new_node);
}

/// @brief add new node to the end of the list
/// @param lst list to add new node to
/// @param new_node new node to the list
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

/// @brief gets the size of the list
/// @param lst list to count nodes
/// @return the size of the list
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/// @brief prints/output string
/// @param s string to print/output
/// @param fd file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
