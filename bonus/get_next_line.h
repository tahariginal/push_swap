/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:02 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 19:29:49 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

size_t	ft_strlen(char *str);
int		ft_search(char *str, char c);
char	*ft_check_str(char *str, int size);
char	*ft_strmcut(char *dest, char *src);
char	*get_next_line(int fd);
#endif
