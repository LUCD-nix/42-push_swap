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

void	test_fn(void *str)
{
	ft_putendl_fd((char *)str, 1);
}
int	main(void)
{
	t_list *tester;
	t_list *ops;
	t_stack *a;
	t_stack *b;
	int		arr[8] = {4 ,5, 2, 7, 0, 1, 3, 6};
	int		i;

	i = -1;
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	tester = NULL;
	while (++i < 8)
		ft_lstadd_back(&tester, ft_lstnew(&arr[i]));
	a->top = tester;
	a->bottom = ft_lstlast(tester);
	b->top = NULL;
	b->bottom = NULL;
	ops = NULL;
	quicksort_a(a, b, ops, 8);
	ft_lstiter(ops, &test_fn);
}
