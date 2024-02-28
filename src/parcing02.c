/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:36 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/28 08:58:51 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (0);
	current = lst;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_digit(char *s)
{
	while (*s == 32)
	{
		if (*(s + 1) == '\n')
			putts("Error");
		s++;
	}
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '-' || *s == '+' || !*s)
	{
		putts("Error");
		exit(1);
	}
	while ((*s && *s <= '9' && *s >= '0') || *s == 32)
		s++;
	if (!*s)
		return (1);
	else if (*s != '-' || *s != '+')
	{
		putts("Error");
		exit(1);
	}
	return (1);
}

int	is_duplicate(t_list *data, int for_search)
{
	while (data->next)
	{
		if (data->next->content == for_search)
			return (0);
		data = data->next;
	}
	return (1);
}
