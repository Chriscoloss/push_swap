/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:18:35 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 20:26:07 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sort_reverse.c: Shifts down all elements (stack A). Last element = first one.
void	rra(int *stack_a, int *amount_a)
{
	int	temp;
	int	i;

	if (*amount_a < 2)
		return ;
	i = *amount_a - 1;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	ft_printf("rra\n");
}

// sort_reverse.c: Shifts down all elements (stack B). Last element = first one.
void	rrb(int *stack_b, int *amount_b)
{
	int	temp;
	int	i;

	if (*amount_b < 2)
		return ;
	i = *amount_b - 1;
	temp = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	ft_printf("rrb\n");
}

// sort_reverse.c: Shifts rra and rrb down at the same time.
void	rrr(int *stack_a, int *stack_b, int *amount_a, int *amount_b)
{
	int	temp_a;
	int	temp_b;
	int	i;

	if (*amount_a < 2 && *amount_b < 2)
		return ;
	i = *amount_a - 1;
	temp_a = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp_a;
	i = *amount_b - 1;
	temp_b = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp_b;
	ft_printf("rrr\n");
}
