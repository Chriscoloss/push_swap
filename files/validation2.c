/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:28:10 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 22:31:11 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Foreword:

// What is a valid Input?

// Valid:		- spaces between numbers or at beginning or end (allowed)
//				- one '-' or '+' char before a number (allowed)
//				- Multiplie Strings that have a valid inputs

// Invalid:		- Numbers with more than 10 digits (not allowed)
//				- Numbers that are bigger than INT_MAX (not allowed)
//				- Numbers that are smaller than INT_MIN (not allowed)

// Function that checks if the string is valid:
int	string_clean_check(char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if ((str[i] == '-' && str[i + 1] >= '0' && str[i] <= '9')
			|| (str[i] == '+' && str[i + 1] >= '0' && str[i] <= '9'))
			i++;
		count = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			count++;
			i++;
		}
		if ((str[i] != '\0' && str[i] != ' ') || count > 10)
			return (1);
	}
	if (int_range_check(str))
		return (1);
	return (0);
}

// Function that checks if the Numbers is in range of (INT_MIN <-> INT_MAX)
int	int_range_check(char *str)
{
	char	**number;
	int		i;

	i = 0;
	number = ft_split(str, ' ');
	if (number == NULL)
		return (1);
	while (number[i])
		if (ft_atol(number[i]) < INT_MIN || ft_atol(number[i++]) > INT_MAX)
			return (1);
	i = 0;
	free_it(number);
	return (0);
}

// Function that sorts a stack if the amount of Numbers is 3
void	sort_three(int *stack_a, int amount)
{
	if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] > stack_a[2])
	{
		sa(stack_a, &amount);
		rra(stack_a, &amount);
	}
	if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] < stack_a[2])
	{
		rra(stack_a, &amount);
		sa(stack_a, &amount);
	}
	if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[0] < stack_a[2])
		sa(stack_a, &amount);
	if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2])
		ra(stack_a, &amount);
	if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2])
		rra(stack_a, &amount);
}
