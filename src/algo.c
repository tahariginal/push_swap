/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:02 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 22:50:45 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	*array_sorted;
	int	size;

	size = lstsize(*stack_a);
	array_sorted = fill_array(*stack_a);
	bubble_sort(array_sorted, lstsize(*stack_a));
	if (size == 2)
		ft_swap(stack_a, 'a');
	else if (size == 3)
		sort_three_element(stack_a);
	else if (size == 5 || size == 4)
		sort_five_element(stack_a, stack_b);
	else if (size <= 100)
		sort_big_element(stack_a, stack_b, array_sorted, 15);
	else if (size > 100)
		sort_big_element(stack_a, stack_b, array_sorted, 30);
	free(array_sorted);
	free_all(stack_a, stack_b);
}
