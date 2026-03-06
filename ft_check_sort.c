/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramalan <nramalan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:11:33 by nramalan          #+#    #+#             */
/*   Updated: 2026/02/24 12:19:51 by nramalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

int	ft_check_array_sorted(int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (numbers[i] > numbers[i + 1])
			return (0);
		i++;
	}
	if (i == (size - 1))
		return (1);
	return (0);
}

int	ft_check_stack_sorted(t_stack *stack, int size)
{
	t_stack	*curr;
	int		i;

	if (!stack && size <= 1)
		return (1);
	if (size <= 1)
		return (1);
	i = 0;
	curr = stack;
	while (i < (size - 1) && curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}
