/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:22 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/24 23:32:43 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(int *ptr)
{
	ptr = NULL;
}

void	clearlst(t_list **lst, void (*del)(int *))
{
	t_list	*i;
	t_list	*tmp;

	if (*lst == NULL || del == NULL || lst == NULL)
		return ;
	i = *lst;
	while (i)
	{
		tmp = i;
		i = i->next;
		del(&tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
