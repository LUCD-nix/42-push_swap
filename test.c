/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
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
void	lstprintnbr(void *i)
{
	ft_putnbr_fd(*(int *)i, 1);
	ft_putchar_fd('\n', 1);
}
int	main(void)
{
	// t_stack *a;
	// t_stack *b;
	// t_list	*tester;
	// int		i;
	// int		arr[3] = { 0, 1, 2};
	// t_list	*ops;
	//
	// tester = NULL;
	// ops = NULL;
	// i = -1;
	// while (++i < 3)
	// 	ft_lstadd_back(&tester, ft_lstnew(&arr[i]));
	// a = ft_calloc(sizeof(t_stack), 1);
	// b = ft_calloc(sizeof(t_stack), 1);
	// ft_lstiter(tester, &lstprintnbr);
	// a->top = tester;
	// a->bottom = ft_lstlast(tester);
	// rrotate_a(&a, &ops);
	// ft_lstiter(a->top, &lstprintnbr);
	// push_b(&a, &b, &ops);
	// push_b(&a, &b, &ops);
	// ft_lstiter(b->top, &lstprintnbr);
	// sort_2b(&b, &ops);
	// ft_lstiter(b->top, &lstprintnbr);
	// rotate_a(&a, &ops);
	// ft_lstiter(a->top, &lstprintnbr);
	t_list *tester;
	t_list *ops;
	t_stack *a;
	t_stack *b;
	int		arr[100] = { 31, 52, 33, 34, 37, 15, 87, 3, 96, 21, 19, 27, 86, 24, 78, 63, 0, 26, 93, 23, 49, 57, 6, 68, 16, 67, 30, 74, 66, 81, 56, 12, 62, 43, 61, 25, 70, 10, 55, 82, 54, 42, 51, 41, 79, 84, 99, 46, 5, 47, 92, 83, 95, 65, 53, 94, 36, 60, 75, 48, 80, 45, 85, 29, 14, 7, 71, 32, 35, 72, 98, 91, 89, 11, 90, 20, 69, 58, 50, 18, 76, 17, 2, 59, 4, 64, 1, 8, 38, 13, 28, 40, 97, 9, 88, 73, 39, 77, 44, 22 };
	int		i;

	i = -1;
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	tester = NULL;
	while (++i < 100)
		ft_lstadd_back(&tester, ft_lstnew(&arr[i]));
	a->top = tester;
	a->bottom = ft_lstlast(tester);
	b->top = NULL;
	b->bottom = NULL;
	ops = NULL;
	a = quicksort_a(&a, &b, &ops, 100);
#ifdef PRUNER
	prune_iter(&ops);
#endif
	ft_lstiter(a->top, &lstprintnbr);
	ft_lstiter(ops, &lstprintchr);// return (1);
}
