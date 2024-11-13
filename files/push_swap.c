/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:50:26 by chorst            #+#    #+#             */
/*   Updated: 2024/05/29 11:57:45 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function that initilaze the stack struct
void	init_stack(t_stack *stack, int amount)
{
	stack->amount_b = 0;
	stack->min_a = INT_MAX;
	stack->max_a = INT_MIN;
	stack->min_b = INT_MAX;
	stack->max_b = INT_MIN;
	stack->parts = find_sweetspot(amount);
	stack->current = 0;
	stack->lowers = 0;
}

// Function that checks if the stack_a is already sorted
int	is_sorted(int *stack_a, int amount_a)
{
	int	i;

	i = 0;
	while (i < amount_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// Function that dynamicly allocates memory for stack_a or stack_b
void	*my_malloc(void *ptr, size_t new_size)
{
	ptr = ft_calloc(sizeof(int), new_size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

// Function to free the stacks to avoid leaks
void	just_free(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
}

// The main (of course)
int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	size_t	amount;

	stack_a = NULL;
	stack_b = NULL;
	if (input_check(argc, argv))
		return (ft_printf("%sError\n%s", R, D));
	amount = (size_t)count_argv_nbrs(argc, argv);
	stack_a = my_malloc(stack_a, amount + 1);
	stack_b = my_malloc(stack_b, amount + 1);
	if (!stack_a || !stack_b)
		return (ft_printf("%sError\n%s", R, D));
	strings_to_nbrs(argc, argv, stack_a);
	if (duplicated_nbrs_check(stack_a, amount))
		return (ft_printf("%sError\n%s", R, D), just_free(stack_a, stack_b), 1);
	if (is_sorted(stack_a, amount))
		return (just_free(stack_a, stack_b), 0);
	call_algorythm(stack_a, stack_b, amount);
	return (just_free(stack_a, stack_b), 0);
}
