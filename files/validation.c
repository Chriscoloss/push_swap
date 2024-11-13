/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:41:27 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 16:28:33 by chorst           ###   ########.fr       */
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

// Helper Function to make the code shorter
int	input_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
		if (string_clean_check(argv[i++]))
			return (1);
	return (0);
}

// ft_atoi funktion but works with long instead of int fo comparison to
// (INT_MIN <-> INT_MAX)
long	ft_atol(const char *str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// Function that checks for duplicated Numbers
int	duplicated_nbrs_check(int *nbrs, int size)
{
	int	i;
	int	x;

	i = 0;
	while (i < size - 1)
	{
		x = i + 1;
		while (x < size)
		{
			if (nbrs[i] == nbrs[x])
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}
