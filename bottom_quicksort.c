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

int	ft_lstmedian_bottom(t_list	*lst, size_t n)
{
	size_t	i;
	size_t	len;
	int		*arr;
	int		res;

	arr = NULL;
	arr = ft_calloc(n, sizeof(int));
	// TODO : 
	// if (!arr)
	// 	exit_error()
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
	// TODO : apply this where relevant
	free(arr);
	return (res);
}

t_stack	*qs_bottom_a(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	int pivot;
	size_t i;

	if (len == 1)
		return (rrotate_a(a, ops));
	if (len == 2)
		return (rrotate_a(a, ops), rrotate_a(a, ops), sort_2a(a, ops));
	pivot = ft_lstmedian_bottom((*a)->top, len);
	i = -1;
	while (++i < len)
	{
		rrotate_a(a, ops);
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
	int pivot;
	size_t i;

	if (len == 1)
		return (rrotate_b(b, ops));
	if (len == 2)
		return (rrotate_b(b, ops), rrotate_b(b, ops), sort_2b(b, ops));
	pivot = ft_lstmedian_bottom((*b)->top, len);
	i = -1;
	while (++i < len)
	{
		rrotate_b(b, ops);
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
