/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:01:56 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 23:25:21 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack(int ac, char **av)
{
	int		i;
	int		j;
	char	**nbrs;
	t_list	*stack_a;

	i = 0;
	j = 0;
	nbrs = NULL;
	stack_a = NULL;
	while (++i < ac)
	{
		j = 0;
		nbrs = ft_split(av[i]);
		while (nbrs[j])
		{
			if (is_digit(nbrs[j]))
				addback(&stack_a, newlst(ft_atoi(nbrs[j++])));
			else
				putts("Error!");
		}
		ft_free(nbrs);
	}
	if (lstsize(stack_a) <= 1)
		exit(1);
	return (stack_a);
}

int	ft_atoi(char *s)
{
	long	r;
	int		sign;
	long	final_result;

	r = 0;
	sign = 1;
	final_result = 0;
	while (*s == 32)
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s && *s <= '9' && *s >= '0')
	{
		r = (r * 10) + (*s - 48);
		s++;
	}
	final_result = sign * r;
	if (final_result <= 2147483647 && final_result >= -2147483648)
		return (sign * r);
	else
		putts("Error");
	exit(1);
	return (0);
}

void	is_dup(t_list *tmp)
{
	while (tmp)
	{
		if (is_duplicate(tmp, tmp->content))
			tmp = tmp->next;
		else
		{
			putts("Error");
			exit (1);
		}
	}
}

void	free_all(t_list **stack_a, t_list **stack_b)
{
	clearlst(stack_a, del);
	clearlst(stack_b, del);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
