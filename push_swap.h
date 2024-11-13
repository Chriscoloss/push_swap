/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:44:24 by chorst            #+#    #+#             */
/*   Updated: 2024/05/22 22:44:43 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librarys
# include "ext_files/getline/get_next_line.h"
# include "ext_files/lib_ft/libft.h"
# include "ext_files/printf_but_ft/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Define Colours
# define R "\033[0;31m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define Y "\033[0;93m"
# define D "\033[0m"

//		### 	FUNCTIONS		###		//

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	amount_a;
	int	amount_b;
	int	min_a;
	int	max_a;
	int	min_b;
	int	max_b;
	int	parts;
	int	current;
	int	lowers;
}		t_stack;

int		is_sorted(int *stack_a, int amount_a);

// algorythm.c
void	pre_sort(t_stack *stack, int *stack_a, int *stack_b, int *amount_a);
void	call_algorythm(int *stack_a, int *stack_b, int amount_a);
void	handle_min_and_max(int *stack_a, int *amount_a, t_stack *stack);
void	not_min_or_max(int *stack_a, int *stack_b, int *amount_a,
			t_stack *stack);

// helper_functions.c
void	min_and_max(int stack, int *min, int *max);
int		lowest_part(int *stack_a, int amount, int parts);
int		no_lowers(int *stack_a, int amount_a, int lowers);
int		find_sweetspot(int amount);

// push_swap.c
void	init_stack(t_stack *stack, int amount);
void	*my_malloc(void *ptr, size_t new_size);
void	just_free(int *stack_a, int *stack_b);

// convertion.c
void	strings_to_nbrs(int argc, char **argv, int *stack_a);
int		count_argv_nbrs(int argc, char **argv);

// validation.c
int		input_check(int argc, char **argv);
long	ft_atol(const char *str);
int		duplicated_nbrs_check(int *nbrs, int size);

// validation2.c
int		int_range_check(char *str);
int		string_clean_check(char *str);
void	sort_three(int *stack_a, int amount);

//		###		SORTING RULES	###		//

// sort_push.c

void	pa(int *stack_a, int *stack_b, int *amount_a, int *amount_b);
void	pb(int *stack_a, int *stack_b, int *amount_a, int *amount_b);

// sort_reverse.c

void	rra(int *stack_a, int *amount_a);
void	rrb(int *stack_b, int *amount_b);
void	rrr(int *stack_a, int *stack_b, int *amount_a, int *amount_b);

// sort_rotate.c

void	ra(int *stack_a, int *amount_a);
void	rb(int *stack_b, int *amount_b);
void	rr(int *stack_a, int *stack_b, int *amount_a, int *amount_b);

// sort_swap.c

void	sa(int *stack_a, int *amount_a);
void	sb(int *stack_b, int *amount_b);
void	ss(int *stack_a, int *stack_b, int *amount_a, int *amount_b);

#endif
