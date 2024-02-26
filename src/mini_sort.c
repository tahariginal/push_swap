/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:28 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/24 23:36:47 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_element(t_list **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	bottom = (*stack_a)->next->next->content;
	if (top > middle && middle < bottom && top < bottom)
		ft_swap(stack_a, 'a');
	else if (top > middle && middle > bottom)
	{
		ft_swap(stack_a, 'a');
		ft_reverse_rotation(stack_a, 'a');
	}
	else if (top < middle && middle > bottom && top > bottom)
		ft_reverse_rotation(stack_a, 'a');
	else if (top < middle && middle > bottom && top < bottom)
	{
		ft_reverse_rotation(stack_a, 'a');
		ft_swap(stack_a, 'a');
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_rotation(stack_a, 'a');
}

void	sort_five_element(t_list **stack_a, t_list **stack_b)
{
	int	smallnbr;

	smallnbr = 0;
	while (lstsize(*stack_a) > 3)
	{
		smallnbr = get_smallest(*stack_a);
		while (get_position(*stack_a, smallnbr))
		{
			if (get_position(*stack_a, smallnbr) < lstsize(*stack_a) / 2)
				ft_rotation(stack_a, 'a');
			else
				ft_reverse_rotation(stack_a, 'a');
		}
		ft_push(stack_a, stack_b, 'b');
	}
	sort_three_element(stack_a);
	ft_push(stack_b, stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
}
