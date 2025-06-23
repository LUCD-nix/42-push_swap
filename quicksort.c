/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:02:52 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:02 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	ft_lst_issort_n(t_list *lst, size_t n, int sign)
{
	size_t	i;
	int		current;
	int		next;

	i = 0;
	while (i < n && lst->next)
	{
		current = *(int *) lst->content;
		next = *(int *) lst->next->content;
		if (sign * current > sign * next)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

static void	qs_b_inner(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	t_list	*tmp;
	size_t	i;
	int		pivot;

	tmp = (*b)->top;
	i = -1;
	pivot = ft_stack_median(b, a, ops, len);
	while (++i < len)
	{
		if (*((int *)tmp->content) > pivot)
			push_a(a, b, ops);
		else
			rotate_b(a, b, ops);
		tmp = (*b)->top;
	}
}

static void	qs_a_inner(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	t_list	*tmp;
	size_t	i;
	int		pivot;

	tmp = (*a)->top;
	i = -1;
	pivot = ft_stack_median(a, b, ops, len);
	while (++i < len)
	{
		if (*((int *)tmp->content) <= pivot)
			push_b(a, b, ops);
		else
			rotate_a(a, b, ops);
		tmp = (*a)->top;
	}
}

t_stack	*quicksort_a(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	size_t	i;
	char	full_stack;

	full_stack = (len == (size_t) ft_lstsize((*a)->top));
	if (len <= 1 || ft_lst_issort_n((*a)->top, len, 1))
		return (*a);
	if (len == 2)
		return (sort_2a(a, b, ops));
	qs_a_inner(a, b, ops, len);
	if (full_stack)
		quicksort_a(a, b, ops, (len / 2));
	else
		qs_bottom_a(a, b, ops, (len / 2));
	quicksort_b(a, b, ops, (len - len / 2));
	i = -1;
	while (++i < (len - len / 2))
		push_a(a, b, ops);
	return (*a);
}

t_stack	*quicksort_b(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	size_t	i;
	char	full_stack;

	full_stack = (len == (size_t) ft_lstsize((*b)->top));
	if (len <= 1 || ft_lst_issort_n((*b)->top, len, -1))
		return (*b);
	if (len == 2)
		return (sort_2b(a, b, ops));
	qs_b_inner(a, b, ops, len);
	quicksort_a(a, b, ops, len / 2);
	if (full_stack)
		quicksort_b(a, b, ops, (len - len / 2));
	else
		qs_bottom_b(a, b, ops, (len - len / 2));
	i = -1;
	while (++i < (len / 2))
		push_b(a, b, ops);
	return (*b);
}
