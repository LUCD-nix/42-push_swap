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

static t_stack	*sort_2a(t_stack **a, t_list **ops)
{
	t_list	*first;
	t_list	*second;
	int		*tmp;

	first = (*a)->top;
	second = (*a)->top->next;
	if (*(int*) first->content > *(int*) second->content)
	{
		tmp = first->content;
		first->content = second->content;
		second->content = tmp;
		ft_lstadd_back(ops, ft_lstnew("sa"));
	}
	return (*a);
}

static t_stack	*sort_2b(t_stack **b, t_list **ops)
{
	t_list	*first;
	t_list	*second;
	int		*tmp;

	first = (*b)->top;
	second = (*b)->top->next;
	if (*(int*) first->content < *(int*) second->content)
	{
		tmp = first->content;
		first->content = second->content;
		second->content = tmp;
		ft_lstadd_back(ops, ft_lstnew("sb"));
	}
	return (*b);
}

t_stack	*quicksort_a(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	int		pivot;
	size_t	i;
	t_list	*tmp;

	if (len <= 1)
		return (*a);
	if (len == 2)
		return (sort_2a(a, ops));
	pivot = ft_lstmedian((*a)->top, len);
	tmp = (*a)->top;
	i = -1;
	while (++i < len)
	{
		if (*((int *)tmp->content) <= pivot)
			push_b(a, b, ops);
		else
			rotate_a(a, ops);
		tmp = (*a)->top;
	}
	i = -1;
	while (++i < len / 2)
		rrotate_a(a, ops);
	quicksort_a(a, b, ops, len / 2);
	quicksort_b(a, b, ops, (len / 2 + len % 2));
	i = -1;
	while (++i < (len / 2 + len % 2))
		push_a(a, b, ops);
	return (*a);
}

t_stack	*quicksort_b(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	int		pivot;
	size_t	i;
	t_list	*tmp;

	if (len <= 1)
		return (*b);
	if (len == 2)
		return (sort_2b(b, ops));
	pivot = ft_lstmedian((*b)->top, len);
	tmp = (*b)->top;
	i = -1;
	while (++i < len)
	{
		if (*((int *)tmp->content) > pivot)
			push_a(a, b, ops);
		else
			rotate_b(b, ops);
		tmp = (*b)->top;
	}
	i = -1;
	while (++i < len / 2)
		rrotate_b(b, ops);
	quicksort_b(a, b, ops, len / 2 + len % 2);
	quicksort_a(a, b, ops, len / 2);
	i = -1;
	while (++i < (len / 2 + len % 2))
		 push_b(a, b, ops);
	return (*b);
}
