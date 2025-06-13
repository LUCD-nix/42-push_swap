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
	int		arr[100] = { 69, 95, 19, 23, 58, 67, 50, 30, 17, 57, 85, 64, 88, 42, 92, 12, 4, 84, 73, 11, 91, 98, 54, 47, 31, 75, 90, 51, 65, 56, 5, 32, 99, 44, 33, 83, 66, 53, 2, 14, 46, 39, 24, 13, 71, 45, 18, 49, 9, 63, 48, 40, 43, 77, 6, 1, 8, 94, 60, 37, 72, 78, 93, 62, 59, 22, 87, 3, 35, 41, 86, 26, 20, 52, 82, 79, 81, 15, 16, 74, 25, 38, 89, 10, 76, 21, 29, 0, 68, 80, 61, 28, 97, 27, 34, 70, 36, 55, 7, 96 };
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
