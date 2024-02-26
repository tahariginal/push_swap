/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:49:32 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 23:04:41 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_list **stk_a, t_list **stk_b)
{
	ft_swap(stk_a, 'x');
	ft_swap(stk_b, 'x');
}

void	rr(t_list **stk_a, t_list **stk_b)
{
	ft_rotation(stk_a, 'x');
	ft_rotation(stk_b, 'x');
}

void	rrr(t_list **stk_a, t_list **stk_b)
{
	ft_reverse_rotation(stk_a, 'x');
	ft_reverse_rotation(stk_b, 'x');
}

void	apply_actions(char *str, t_list **stk_a, t_list **stk_b)
{
	if (!ft_strncmp(str, "pa\n", 3))
		ft_push(stk_a, stk_b, 'x');
	else if (!ft_strncmp(str, "pb\n", 3))
		ft_push(stk_a, stk_b, 'x');
	else if (!ft_strncmp(str, "sa\n", 3))
		ft_swap(stk_a, 'x');
	else if (!ft_strncmp(str, "sb\n", 3))
		ft_swap(stk_b, 'x');
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(stk_a, stk_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		ft_rotation(stk_a, 'x');
	else if (!ft_strncmp(str, "rb\n", 3))
		ft_rotation(stk_b, 'x');
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(stk_a, stk_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		ft_reverse_rotation(stk_a, 'x');
	else if (!ft_strncmp(str, "rrb\n", 4))
		ft_reverse_rotation(stk_b, 'x');
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(stk_a, stk_b);
	else
		(putts("ERROR"), exit(1));
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	char	*cmd;
	char	*help;

	if (ac == 1)
		exit(1);
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	tmp = stack_a;
	is_dup(tmp);
	cmd = get_next_line(0);
	while (cmd)
	{
		help = cmd;
		apply_actions(cmd, &stack_a, &stack_b);
		free(help);
		cmd = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&stack_a, &stack_b);
}
