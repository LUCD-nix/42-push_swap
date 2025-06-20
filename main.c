/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:24 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:34 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	lstprintchr(void *str)
{
	ft_putendl_fd((char *)str, 1);
}

t_list	*array_to_str_list(char **arr)
{
	t_list	*strings;
	t_list	*to_add;
	int		i;

	i = -1;
	strings = NULL;
	while (arr[++i])
	{
		to_add = NULL;
		to_add = ft_lstnew(arr[i]);
		if (!to_add)
			exit_error_input_treatment(&arr, &strings);
		ft_lstadd_back(&strings, to_add);
	}
	return (strings);
}

void	alloc_stacks(t_stack **a, t_stack **b)
{
	*a = NULL;
	*b = NULL;
	*a = ft_calloc(1, sizeof(t_stack));
	*b = ft_calloc(1, sizeof(t_stack));
	if (!*a || !*b)
		exit_error_stack_malloc(a, b, NULL);
}

void	sort_and_exit(t_stack **a, t_stack **b)
{
	t_list	*ops;

	ops = NULL;
	*a = quicksort_a(a, b, &ops, ft_lstsize((*a)->top));
	prune_iter(&ops);
	ft_lstiter(ops, &lstprintchr);
	free_ops_and_stacks(&ops, a, b);
}

int	main(int argc, char **argv)
{
	char	**temp;
	t_list	*strings;
	t_list	*numbers;
	t_stack	*a;
	t_stack	*b;

	temp = input_to_heap_array(argc, argv);
	strings = array_to_str_list(temp);
	check_input_iter(&strings, &temp);
	numbers = NULL;
	numbers = ft_lstmap(strings, &ps_atoi, &free);
	if (!numbers)
		exit_error_input_treatment(&temp, &strings);
	free_strs(&temp, &strings);
	alloc_stacks(&a, &b);
	a->top = numbers;
	a->bottom = ft_lstlast(numbers);
	sort_and_exit(&a, &b);
	return (EXIT_SUCCESS);
}
