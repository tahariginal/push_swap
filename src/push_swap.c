/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:39 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 23:24:55 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	if (ac == 1)
		exit(1);
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	tmp = stack_a;
	while (tmp)
	{
		if (is_duplicate(tmp, tmp->content))
			tmp = tmp->next;
		else
		{
			putts("Error");
			exit(1);
		}
	}
	tmp = stack_a;
	if (!is_sorted(tmp))
		sort(&stack_a, &stack_b);
	exit(1);
}
