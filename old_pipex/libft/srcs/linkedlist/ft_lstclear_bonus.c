/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 04:30:20 by htoe              #+#    #+#             */
/*   Updated: 2026/01/16 05:10:54 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		temp = current -> next;
		del(current -> content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}
