/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:44 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 06:24:40 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	y;
	int	tmp;

	i = 0;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
		{
			if (arr[i] > arr[y])
			{
				tmp = arr[i];
				arr[i] = arr[y];
				arr[y] = tmp;
			}
			y++;
		}
		i++;
	}
}

int	get_position(t_list *lst, int value)
{
	int	position;

	position = 0;
	while (lst->content != value)
	{
		position++;
		lst = lst->next;
	}
	return (position);
}

int	get_position_of_big_index(t_list *lst)
{
	int	position;
	int	big_index;

	position = 0;
	big_index = lstsize(lst) - 1;
	while (lst->index != big_index)
	{
		position++;
		lst = lst->next;
	}
	return (position);
}

void	check_index(t_list **stack_a, int i, int proxime)
{
	int		j;
	t_list	*tmp;

	j = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index <= i || tmp->index <= i + proxime)
			break ;
		j++;
		tmp = tmp->next;
	}
	if (j < lstsize(*stack_a) / 2)
		ft_rotation(stack_a, 'a');
	else
		ft_reverse_rotation(stack_a, 'a');
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((t_byte)s1[i] - (t_byte)s2[i]);
}
