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

#include "libft/libft.h"
#include "push_swap.h"

t_stack	sort_2b(t_stack **b, t_list **ops);

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
	int		arr[16] = { 0, 13, 11, 12, 5, 7, 9, 8, 14, 10, 4, 15, 2, 3, 1, 6 };
	int		i;

	i = -1;
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	tester = NULL;
	while (++i < 16)
		ft_lstadd_back(&tester, ft_lstnew(&arr[i]));
	a->top = tester;
	a->bottom = ft_lstlast(tester);
	b->top = NULL;
	b->bottom = NULL;
	ops = NULL;
	a = quicksort_a(&a, &b, &ops, 16);
#ifdef PRUNER
	prune_iter(&ops);
#endif
	ft_lstiter(a->top, &lstprintnbr);
	ft_lstiter(ops, &lstprintchr);// return (1);
}
