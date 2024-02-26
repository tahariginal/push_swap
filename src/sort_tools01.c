/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:41 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 07:04:52 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_list *lst)
{
	int	min;

	min = INT_MAX;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	get_big_nbr(t_list *lst)
{
	int		max;
	t_list	*tmp;

	max = INT_MIN;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	*fill_array(t_list *lst)
{
	int	*array;
	int	i;
	int	size;

	array = malloc(lstsize(lst) * sizeof(int));
	i = 0;
	size = lstsize(lst);
	while (i < size)
	{
		array[i] = lst->content;
		i++;
		lst = lst->next;
	}
	return (array);
}

void	index_each_nbr(t_list *lst, int *array)
{
	int	i;
	int	size;

	i = 0;
	size = lstsize(lst);
	while (lst)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == lst->content)
			{
				lst->index = i;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

void	putts(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
	write(1, "\n", 1);
}
