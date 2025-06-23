/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:24 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:34 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <errno.h>
#include <stdlib.h>

void	exit_error_sort_malloc(t_stack **stack1, t_stack **stack2,
			t_list **ops)
{
	free_ops_and_stacks(ops, stack1, stack2);
	ft_printf("Error\n");
	errno = ENOMEM;
	exit(EXIT_FAILURE);
}

void	exit_error_stack_malloc(t_stack **a, t_stack **b, t_list **ops)
{
	free_ops_and_stacks(ops, a, b);
	ft_printf("Error\n");
	errno = ENOMEM;
	exit(EXIT_FAILURE);
}

void	exit_error_input_treatment(char ***str_arr, t_list **strings)
{
	free_strs(str_arr, strings);
	ft_printf("Error\n");
	errno = EIO;
	exit(EXIT_FAILURE);
}
