/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karatsar <karatsar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:46:26 by nramalan          #+#    #+#             */
/*   Updated: 2026/03/04 09:43:09 by karatsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_stack_push(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	if (*stack)
	{
		(*stack)->prev = node;
		node->next = *stack;
	}
	*stack = node;
}

void	ft_stackadd_back(t_stack **stacks, t_stack *node)
{
	t_stack	*stack;

	if (!stacks || !node)
		return ;
	if (*stacks)
	{
		stack = *stacks;
		while (stack->next)
			stack = stack->next;
		stack->next = node;
		node->prev = stack;
	}
	else
		*stacks = node;
}

void	ft_stack_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

void	ft_stack_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	top = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}

void	ft_stack_reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	bottom->next = *stack;
	bottom->prev = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
