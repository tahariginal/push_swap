/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:15 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 22:37:54 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_element(t_list **stack_a, t_list **stack_b, int *array_sorted,
		int proxime)
{
	int	i;

	i = 0;
	index_each_nbr(*stack_a, array_sorted);
	push_to_b(stack_a, stack_b, i, proxime);
	push_to_a(stack_a, stack_b);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	big_index;

	big_index = 0;
	while (*stack_b)
	{
		big_index = lstsize(*stack_b) - 1;
		while (big_index != (*stack_b)->index)
		{
			if (get_position_of_big_index(*stack_b) < lstsize(*stack_b) / 2)
				ft_rotation(stack_b, 'b');
			else
				ft_reverse_rotation(stack_b, 'b');
		}
		ft_push(stack_b, stack_a, 'a');
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int i, int proxime)
{
	int	end;
	int	y;

	end = lstsize(*stack_a);
	y = 0;
	while (y < end)
	{
		if ((*stack_a)->index <= i)
		{
			ft_push(stack_a, stack_b, 98);
			ft_rotation(stack_b, 98);
			i++;
			y++;
		}
		else if ((*stack_a)->index <= i + proxime)
		{
			ft_push(stack_a, stack_b, 98);
			y++;
			i++;
		}
		else
			check_index(stack_a, i, proxime);
	}
}
