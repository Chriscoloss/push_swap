/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:49:49 by chorst            #+#    #+#             */
/*   Updated: 2024/05/13 15:44:02 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function that converts all strings (argv's) into array of nbr (int *nbr)
void	strings_to_nbrs(int argc, char **argv, int *stack_a)
{
	int	x;
	int	b;
	int	i;

	x = 0;
	b = 0;
	while (b < argc)
	{
		i = 0;
		while (argv[b][i])
		{
			if ((argv[b][i] == '-' && argv[b][i + 1] >= '0' && argv[b][i
					+ 1] <= '9') || (argv[b][i] >= '0' && argv[b][i] <= '9'))
			{
				stack_a[x++] = ft_atoi(&argv[b][i]);
				while (argv[b][i] && (argv[b][i] == '-' || (argv[b][i] >= '0'
							&& argv[b][i] <= '9')))
					i++;
			}
			else
				i++;
		}
		b++;
	}
	argv[b] = 0;
}

// Function that counts the ammount of all numbers inside of all the arguments
int	count_argv_nbrs(int argc, char **argv)
{
	int	count;
	int	i;
	int	x;

	count = 0;
	i = 1;
	while (i < argc)
	{
		x = 0;
		while (argv[i][x])
		{
			while (argv[i][x] == ' ' || argv[i][x] == '+' || argv[i][x] == '-')
				x++;
			if (argv[i][x] >= '0' && argv[i][x] <= '9')
			{
				count++;
				while (argv[i][x] && argv[i][x] != ' ')
					x++;
			}
		}
		i++;
	}
	return (count);
}
