/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:10 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 04:37:52 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char c)
{
	t_list	*tmp;

	if (lstsize(*stack) >= 2)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	ft_push(t_list **stack_1, t_list **stack_2, char c)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*stack_1)
	{
		tmp1 = (*stack_1)->next;
		tmp2 = *stack_1;
		tmp2->next = *stack_2;
		*stack_2 = tmp2;
		*stack_1 = tmp1;
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pb\n", 3);
	}
}

void	ft_rotation(t_list **stack, char c)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = get_last_lst(*stack);
		tmp->next = *stack;
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		*stack = tmp;
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}

void	ft_reverse_rotation(t_list **stack, char c)
{
	t_list	*last;
	t_list	*before_last;

	if (*stack && (*stack)->next)
	{
		last = get_last_lst(*stack);
		before_last = *stack;
		while (before_last->next && before_last->next != last)
			before_last = before_last->next;
		before_last->next = NULL;
		last->next = *stack;
		*stack = last;
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}
