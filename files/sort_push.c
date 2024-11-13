/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:13:55 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 20:24:01 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sort_push.c: Takes the first element B and put it at the top of A
void	pa(int *stack_a, int *stack_b, int *amount_a, int *amount_b)
{
	int	i;

	if (amount_b == 0)
		return ;
	i = *amount_a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < *amount_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = 0;
	(*amount_a)++;
	(*amount_b)--;
	ft_printf("pa\n");
}

// sort_push.c: Takes the first element A and put it at the top of B
void	pb(int *stack_a, int *stack_b, int *amount_a, int *amount_b)
{
	int	i;

	if (amount_a == 0)
		return ;
	i = *amount_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < *amount_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = 0;
	(*amount_a)--;
	(*amount_b)++;
	ft_printf("pb\n");
}
