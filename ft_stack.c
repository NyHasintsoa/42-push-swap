/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:00:00 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:43:05 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static t_stack	*ft_stack_new(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_stack_free(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

static void	ft_assign_index(t_stack *stack, int size)
{
	int		i;
	t_stack	*curr;
	t_stack	*compare;
	int		index;

	curr = stack;
	i = 0;
	while (i < size)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < curr->value)
				index++;
			compare = compare->next;
		}
		curr->index = index;
		curr = curr->next;
		i++;
	}
}

t_stack	*ft_stack_init(int *numbers, int count)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	if (!numbers || count <= 0)
		return (NULL);
	stack = NULL;
	i = 0;
	while (i < count)
	{
		node = ft_stack_new(numbers[i], i);
		if (!node)
		{
			ft_stack_free(&stack);
			return (NULL);
		}
		ft_stackadd_back(&stack, node);
		i++;
	}
	ft_assign_index(stack, count);
	return (stack);
}
