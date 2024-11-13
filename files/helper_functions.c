/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:35:31 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 20:22:46 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// helper_functions.c: Searches for min and max values inside of a stack
void	min_and_max(int stack, int *min, int *max)
{
	if (stack < *min)
		*min = stack;
	if (stack > *max)
		*max = stack;
}

// helper_functions.c: Finds the biggest Number of the lowest Part
int	lowest_part(int *stack_a, int amount, int split)
{
	int	i;
	int	b;
	int	count;

	i = 0;
	b = i + 1;
	count = 0;
	while (i < amount)
	{
		count = 0;
		b = 0;
		while (b < amount - 1)
		{
			if (stack_a[i] > stack_a[b++])
				count++;
			if (count > amount / split)
				break ;
		}
		if (count == (amount / split))
			return (stack_a[i]);
		i++;
	}
	return (stack_a[i]);
}

// helper_functions.c: Checks if lowers exist in stack_a
int	no_lowers(int *stack_a, int amount_a, int lowers)
{
	int	i;

	i = 0;
	while (i < amount_a)
	{
		if (stack_a[i] < lowers)
			return (1);
		i++;
	}
	return (0);
}

// helper_functions.c: Defines Parts depending on the amount of Numbers
int	find_sweetspot(int amount)
{
	if (amount <= 10)
		return (3);
	if (amount <= 100)
		return (4);
	if (amount <= 300)
		return (6);
	if (amount <= 500)
		return (8);
	if (amount <= 700)
		return (10);
	if (amount <= 1000)
		return (12);
	return (0);
}
