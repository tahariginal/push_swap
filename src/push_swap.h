/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:39:19 by tkoulal           #+#    #+#             */
/*   Updated: 2024/02/25 19:54:55 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../bonus/get_next_line.h"
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}					t_list;

typedef unsigned char	t_byte;
// actions;
void				ft_swap(t_list **stack, char c);
void				ft_push(t_list **stack_1, t_list **stack_2, char c);
void				ft_rotation(t_list **stack, char c);
void				ft_reverse_rotation(t_list **stack, char c);
// algotithms;
void				sort(t_list **stack_a, t_list **stack_b);
void				sort_big_element(t_list **stack_a, t_list **stack_b,
						int *array_sorted, int proxime);
void				push_to_b(t_list **stack_a, t_list **stack_b, int i,
						int proxime);
void				push_to_a(t_list **stack_a, t_list **stack_b);
void				sort_three_element(t_list **stack_a);
void				sort_five_element(t_list **stack_a, t_list **stack_b);
// tools;
t_list				*fill_stack(int ac, char **av);
void				ft_free(char **str);
void				free_all(t_list **stack_a, t_list **stack_b);
void				bubble_sort(int *arr, int size);
int					get_position(t_list *lst, int value);
int					get_position_of_big_index(t_list *lst);
void				check_index(t_list **stack_a, int i, int proxime);
int					get_big_nbr(t_list *lst);
int					get_smallest(t_list *lst);
int					*fill_array(t_list *lst);
void				index_each_nbr(t_list *data, int *array);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
// parcing;
void				is_dup(t_list *tmp);
void				putts(char *s);
char				**ft_split(char *str);
int					ft_atoi(char *s);
int					is_sorted(t_list *lst);
int					is_digit(char *s);
int					is_duplicate(t_list *data, int for_search);
// lists;
t_list				*newlst(int v);
t_list				*get_last_lst(t_list *lst);
void				addfront(t_list **lst, t_list *new);
void				addback(t_list **lst, t_list *new);
int					lstsize(t_list *lst);
void				clearlst(t_list **lst, void (*del)(int *));
void				del(int *ptr);

#endif
