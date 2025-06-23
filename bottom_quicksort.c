/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_quicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:02:52 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:02 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

int	ft_stack_median_bottom(t_stack **stack1, t_stack **stack2,
		t_list **ops, size_t n)
{
	size_t	i;
	size_t	len;
	t_list	*lst;
	int		*arr;
	int		res;

	lst = (*stack1)->top;
	arr = NULL;
	arr = ft_calloc(n, sizeof(int));
	if (!arr)
		exit_error_sort_malloc(stack1, stack2, ops);
	i = -1;
	len = ft_lstsize(lst);
	while (++i < len - n)
		lst = lst->next;
	i = -1;
	while (lst)
	{
		arr[++i] = *(int *)lst->content;
		lst = lst->next;
	}
	ft_sort_int_tab(arr, (int)n);
	res = arr[n / 2 - !(n % 2)];
	free(arr);
	return (res);
}

t_stack	*qs_bottom_a(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	int		pivot;
	size_t	i;

	if (len == 1)
		return (rrotate_a(a, b, ops));
	if (len == 2)
		return (rrotate_a(a, b, ops), rrotate_a(a, b, ops), sort_2a(a, b, ops));
	pivot = ft_stack_median_bottom(a, b, ops, len);
	i = -1;
	while (++i < len)
	{
		rrotate_a(a, b, ops);
		if (*((int *)(*a)->top->content) <= pivot)
			push_b(a, b, ops);
	}
	quicksort_a(a, b, ops, len / 2);
	quicksort_b(a, b, ops, len - len / 2);
	i = -1;
	while (++i < (len - len / 2))
		push_a(a, b, ops);
	return (*a);
}

t_stack	*qs_bottom_b(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	int		pivot;
	size_t	i;

	if (len == 1)
		return (rrotate_b(a, b, ops));
	if (len == 2)
		return (rrotate_b(a, b, ops), rrotate_b(a, b, ops), sort_2b(a, b, ops));
	pivot = ft_stack_median_bottom(b, a, ops, len);
	i = -1;
	while (++i < len)
	{
		rrotate_b(a, b, ops);
		if (*((int *)(*b)->top->content) > pivot)
			push_a(a, b, ops);
	}
	quicksort_a(a, b, ops, len / 2);
	quicksort_b(a, b, ops, len - len / 2);
	i = -1;
	while (++i < (len / 2))
		push_b(a, b, ops);
	return (*b);
}
