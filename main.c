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
	int	j;

	temp = NULL;
	// all in one big string;
	if (argc == 2)
		temp = ft_split(argv[1],' ');
	else
		temp = argv + 1;
	i = -1;
	j = -1;
	while (temp[++j])
		;
	strings = NULL;
	// This needs testing but it should be fine
	while (++i < j)
		ft_lstadd_back(&strings, ft_lstnew(temp[i]));
	cursor = strings;
	ops = NULL;
	numbers = NULL;
	while (cursor)
	{
		if (!check_input((char *)cursor->content))
			return(clear_lists(&ops, &numbers));
		cursor = cursor->next;
	}
	numbers = ft_lstmap(strings, &ps_atoi, &free);
	a = NULL;
	b = NULL;
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	// TODO :
	// if (!a || !b)
	// 	exit_error(strings, numbers, a, b);
	a->top = numbers;
	a->bottom = ft_lstlast(numbers);
#include <stdio.h>
	printf("%d\n", ft_lstsize(a->top));
	a = qs_bottom_a(&a, &b, &ops, ft_lstsize(a->top));
	ft_lstiter(a->top, &lstprintnbr);
	return (0);
}
