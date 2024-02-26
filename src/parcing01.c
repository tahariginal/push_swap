/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:31 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 23:25:40 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == 32)
			str++;
		if (*str && *str != 32)
		{
			count++;
			while (*str && *str != 32)
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != 32)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != 32)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_for_norminette(char *str, char **arr)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && *str == 32)
		{
			if (*(str + 1) == '\0')
			{
				putts("Error");
				exit(1);
			}
			str++;
		}
		if (*str && *str != 32)
		{
			arr[i++] = malloc_word(str);
			while (*str && *str != 32)
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		i;

	if (!*str)
	{
		putts("Error");
		exit(1);
	}
	arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	return (ft_for_norminette(str, arr));
}
