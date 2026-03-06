/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:46:45 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 13:48:08 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_type.h"

int			*ft_check_args(int argc, char *argv[]);
int			*ft_check_str(char *argv);
int			ft_total_ops(t_bench	*bench);
int			ft_check_array_sorted(int *numbers, int size);
int			ft_check_stack_sorted(t_stack *stack, int size);

int			ft_strcmp(const char *s1, const char *s2);
long		ft_atol(const char *nptr);

int			ft_isspace(char c);
int			ft_issign(char c);
int			ft_strisnumeric(const char *str);
int			ft_has_dup(int *tab, int size);
int			ft_check_dup(int *numbers, int size);
int			ft_count_numbers(const char *s, char c);
int			ft_words_is_in_range(char **words);

t_stack		*ft_stack_top(t_stack **stack);
void		ft_stackadd_back(t_stack **stacks, t_stack *node);

void		ft_stack_push(t_stack **stack, t_stack *node);
void		ft_stack_swap(t_stack **stack);
void		ft_stack_rotate(t_stack **stack);
void		ft_stack_reverse_rotate(t_stack **stack);

int			ft_stack_size(t_stack *stack);
void		ft_stack_free(t_stack **stack);
t_stack		*ft_stack_init(int *numbers, int count);

void		ft_error(void);
void		ft_exit(void);

#endif
