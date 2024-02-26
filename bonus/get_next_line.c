/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:02 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 19:29:46 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buff)
{
	char	*str;
	ssize_t	len;

	len = 1;
	str = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (ft_search(buff, '\n') < 0 && len > 0)
	{
		len = read(fd, str, BUFFER_SIZE);
		if (len < 0)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		str[len] = '\0';
		buff = ft_strmcut(buff, str);
	}
	free(str);
	return (buff);
}

char	*ft_create_line(char *buff)
{
	int		i;
	int		len;
	char	*str;

	if (!buff[0])
		return (NULL);
	len = ft_search(buff, '\n');
	if (len < 0)
		len = (int) ft_strlen(buff);
	str = (char *)malloc(len + 2 * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = buff[i];
	if (buff[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_clean_line(char *buff)
{
	int		i;
	int		j;
	char	*newbuff;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	newbuff = (char *)malloc(ft_strlen(buff) - i);
	if (!newbuff)
	{
		free(buff);
		return (NULL);
	}
	while (buff[++i])
		newbuff[j++] = buff[i];
	newbuff[j] = '\0';
	free(buff);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || !BUFFER_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read_line(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_create_line(buff);
	buff = ft_clean_line(buff);
	return (line);
}
