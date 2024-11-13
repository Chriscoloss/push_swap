/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:16:23 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 21:15:12 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function that pre-sorts the stack_a and put it to stack_b
void	pre_sort(t_stack *stack, int *stack_a, int *stack_b, int *amount_a)
{
	while (*amount_a > stack->parts)
	{
		stack->lowers = lowest_part(stack_a, *amount_a, stack->parts);
		min_and_max(stack_b[0], &stack->min_b, &stack->max_b);
		while (no_lowers(stack_a, *amount_a, stack->lowers))
		{
			if (stack_a[0] > stack->lowers)
				ra(stack_a, &*amount_a);
			if (stack_a[0] <= stack->lowers)
				pb(stack_a, stack_b, amount_a, &(stack->amount_b));
			if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1])
				ss(stack_a, stack_b, &*amount_a, &stack->amount_b);
			else if (stack_b[0] < stack_b[1])
				sb(stack_b, &stack->amount_b);
		}
	}
	while (*amount_a > 1 && stack->amount_b > 3)
		pb(stack_a, stack_b, amount_a, &(stack->amount_b));
	min_and_max(stack_a[0], &stack->min_a, &stack->max_a);
}

// Function that calls the algorythms
void	call_algorythm(int *stack_a, int *stack_b, int amount_a)
{
	t_stack	stack;

	init_stack(&stack, amount_a);
	if (amount_a == 3)
	{
		sort_three(stack_a, amount_a);
		return ;
	}
	pre_sort(&stack, stack_a, stack_b, &amount_a);
	while (stack.amount_b > 0)
	{
		min_and_max(stack_a[0], &stack.min_a, &stack.max_a);
		if (stack_b[0] < stack.min_a || stack_b[0] > stack.max_a)
			handle_min_and_max(stack_a, &amount_a, &stack);
		else
			not_min_or_max(stack_a, stack_b, &amount_a, &stack);
		pa(stack_a, stack_b, &amount_a, &stack.amount_b);
	}
	min_and_max(stack_a[0], &stack.min_a, &stack.max_a);
	while (stack_a[0] != stack.min_a)
		rra(stack_a, &amount_a);
}

// Function that handles all the min and max values passed from stack_b[0]
void	handle_min_and_max(int *stack_a, int *amount_a, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack_a[i] != stack->min_a)
		i++;
	if (i < *amount_a / 2)
		while (i-- > 0)
			ra(stack_a, amount_a);
	else
		while (i++ < *amount_a)
			rra(stack_a, amount_a);
}

// Function that handles all the values (not min or max) passed from stack_b[0]
void	not_min_or_max(int *stack_a, int *stack_b, int *amount_a,
		t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack->current = INT_MAX;
	while (i < *amount_a)
	{
		if (stack_a[i] > stack_b[0] && stack->current > stack_a[i])
		{
			stack->current = stack_a[i];
			j = i;
		}
		i++;
	}
	if (j >= *amount_a / 2)
		while (j++ < *amount_a)
			rra(stack_a, amount_a);
	else
		while (j-- > 0)
			ra(stack_a, amount_a);
}
