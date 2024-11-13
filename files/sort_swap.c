/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:10:59 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 16:04:24 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sort_swap.c: Swap the first 2 elements at the top of stack A
void	sa(int *stack_a, int *amount_a)
{
	int	temp;
	int	i;

	i = 0;
	if (*amount_a < 2)
		return ;
	temp = stack_a[i];
	stack_a[i] = stack_a[i + 1];
	stack_a[i + 1] = temp;
	ft_printf("sa\n");
}

//  sort_swap.c: Swap the first 2 elements at the top of stack B
void	sb(int *stack_b, int *amount_b)
{
	int	temp;
	int	i;

	i = 0;
	if (*amount_b < 2)
		return ;
	temp = stack_b[i];
	stack_b[i] = stack_b[i + 1];
	stack_b[i + 1] = temp;
	ft_printf("sb\n");
}

// sort_swap.c: Swap sa and sb at the same time
void	ss(int *stack_a, int *stack_b, int *amount_a, int *amount_b)
{
	int	temp;
	int	i;

	i = 0;
	if (*amount_a < 2 || *amount_b < 2)
		return ;
	temp = stack_a[i];
	stack_a[i] = stack_a[i + 1];
	stack_a[i + 1] = temp;
	temp = stack_b[i];
	stack_b[i] = stack_b[i + 1];
	stack_b[i + 1] = temp;
	ft_printf("ss\n");
}
