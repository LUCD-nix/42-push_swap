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
#include "libft/libft.h"
#include "push_swap.h"

void	lstprintchr(void *str)
{
	ft_putendl_fd((char *)str, 1);
}
void	lstprintnbr(void *i)
{
	ft_putnbr_fd(*(int *)i, 1);
	ft_putchar_fd('\n', 1);
}

void *ps_atoi(void *str)
{
	int	*res;

	res = NULL;
	res = ft_calloc(1, sizeof(int));
	if (!res)
		return (NULL);
	*res = ft_atoi((char *)str);
	return ((void *)res);
}

int	clear_lists(t_list	**ops, t_list **numbers)
{
	ft_lstclear(numbers, &free);
	ft_lstclear(ops, &do_nothing);
	return (1);
}

int	check_input(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
char	**input_to_heap_array(int argc, char **argv)
{
	char	**res;
	int	i;

	res = NULL;
	if (argc == 2)
		res = ft_split(argv[1], ' ');
	else
	{
		res = ft_calloc(argc, sizeof(char *));
		if (!res)
			exit_error_input_treatment(&res, NULL);
		i = 0;
		while (i + 1 < argc)
		{
			res[i] = ft_strdup(argv[i + 1]);
			if (!res[i])
				exit_error_input_treatment(&res, NULL);
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	char	**temp;
	t_list	*strings;
	t_list	*cursor;
	t_list	*numbers;
	t_list	*ops;
	t_stack	*a;
	t_stack	*b;
	int	i;

	temp = input_to_heap_array(argc, argv);
	i = -1;
	strings = NULL;
	while (temp[++i])
	{
		t_list	*to_add = NULL;
		to_add = ft_lstnew(temp[i]);
		if (!to_add)
			exit_error_input_treatment(&temp, &strings);
		ft_lstadd_back(&strings, to_add);
	}
	cursor = strings;
	ops = NULL;
	numbers = NULL;
	while (cursor)
	{
		if (!check_input((char *)cursor->content))
			exit_error_input_treatment(&temp, &strings);
		cursor = cursor->next;
	}
	numbers = ft_lstmap(strings, &ps_atoi, &free);
	if (!numbers)
		exit_error_input_treatment(&temp, &strings);
	free_strs(&temp, &strings);
	a = NULL;
	b = NULL;
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	if (!a || !b)
		exit_error_stack_malloc(&a, &b, &ops);
	a->top = numbers;
	a->bottom = ft_lstlast(numbers);
	a = quicksort_a(&a, &b, &ops, ft_lstsize(a->top));
	prune_iter(&ops);
	ft_lstiter(ops, &lstprintchr);
	free_ops_and_stacks(&ops, &a, &b);
	return (0);
}
