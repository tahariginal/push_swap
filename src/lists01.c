/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:18 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/24 23:31:36 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*newlst(int v)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = v;
	new->next = NULL;
	return (new);
}

t_list	*get_last_lst(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}

void	addfront(t_list **lst, t_list *new)
{
	if (lst || new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	addback(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = get_last_lst(*lst);
	last->next = new;
}
