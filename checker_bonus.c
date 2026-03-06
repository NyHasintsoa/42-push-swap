/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:58:29 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/06 09:13:56 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "ft_utils.h"
#include "get_next_line.h"

static int	ft_exec_operation(
	const char *cmd,
	t_stack **stack_a,
	t_stack **stack_b
) {
	if (ft_exec_push(cmd, stack_a, stack_b))
		return (1);
	if (ft_exec_reverse(cmd, stack_a, stack_b))
		return (1);
	if (ft_exec_rotate(cmd, stack_a, stack_b))
		return (1);
	if (ft_exec_swap(cmd, stack_a, stack_b))
		return (1);
	return (0);
}

static int	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		result;

	line = get_next_line(0);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		result = ft_exec_operation(line, stack_a, stack_b);
		free(line);
		if (!result)
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

static char	*ft_execute_checker(t_stack **a, t_stack **b, int size)
{
	int	result;

	result = ft_sort_stack(a, b);
	if (result == 0)
		return ("Error");
	if (ft_check_stack_sorted(*a, size) && (ft_stack_size(*b) == 0))
		return ("OK");
	return ("KO");
}

char	*push_swap_checker(t_opts_checker opts)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*value;

	stack_a = ft_stack_init(opts.numbers, opts.size);
	if (!stack_a)
	{
		free(opts.numbers);
		ft_error();
	}
	stack_b = NULL;
	value = ft_execute_checker(&stack_a, &stack_b, opts.size);
	ft_stack_free(&stack_a);
	ft_stack_free(&stack_b);
	return (value);
}
