/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:29:40 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 19:30:13 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_search(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_check_str(char *str, int size)
{
	if (!str)
	{
		str = (char *)malloc(size);
		if (!str)
			return (NULL);
		str[size - 1] = '\0';
	}
	return (str);
}

char	*ft_strmcut(char *dest, char *src)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	dest = ft_check_str(dest, 1);
	if (!dest || !src)
		return (NULL);
	str = (char *)malloc(ft_strlen(dest) + ft_strlen(src) + 10);
	if (!str)
		return (NULL);
	while (dest[++i])
		str[i] = dest[i];
	while (src[j])
		str[i++] = src[j++];
	str[i] = '\0';
	free(dest);
	return (str);
}
