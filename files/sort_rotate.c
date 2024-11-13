/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:14:20 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 20:28:22 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sort_rotate.c: Shifts up all elements of stack A by 1.
void	ra(int *stack_a, int *amount_a)
{
	int	i;
	int	temp;

	if (*amount_a < 2)
		return ;
	temp = stack_a[0];
	i = 0;
	while (i < *amount_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
	ft_printf("ra\n");
}

// sort_rotate.c: Shifts up all elements of stack B by 1.
void	rb(int *stack_b, int *amount_b)
{
	int	i;
	int	temp;

	if (*amount_b < 2)
		return ;
	temp = stack_b[0];
	i = 0;
	while (i < *amount_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp;
	ft_printf("rb\n");
}

// sort_rotate.c: Shifts ra and rb up at the same time.
void	rr(int *stack_a, int *stack_b, int *amount_a, int *amount_b)
{
	int	i;
	int	temp_a;
	int	temp_b;

	temp_a = stack_a[0];
	i = 0;
	while (i < *amount_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp_a;
	temp_b = stack_b[0];
	i = 0;
	while (i < *amount_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp_b;
	ft_printf("rr\n");
}
