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
#include "libft/libft.h"
#include "push_swap.h"

t_stack	*sort_2a(t_stack **a, t_list **ops)
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

t_stack	*sort_2b(t_stack **b, t_list **ops)
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

char	ft_lst_issort_n(t_list *lst, size_t n, int sign)
{
	size_t	i;
	int		current;
	int		next;

	i = 0;
	while (i < n && lst->next)
	{
		current = *(int*) lst->content;
		next = *(int*) lst->next->content;
		if (sign * current > sign * next)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

t_stack	*quicksort_a(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	int		pivot;
	size_t	i;
	t_list	*tmp;
	char	full_stack;

	full_stack = (len == (size_t) ft_lstsize((*a)->top));
	if (len <= 1 || ft_lst_issort_n((*a)->top, len, 1))
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
	while (!full_stack && ++i < len / 2)
		rrotate_a(a, ops);
	quicksort_a(a, b, ops, (len / 2));
	quicksort_b(a, b, ops, (len  - len / 2));
	i = -1;
	while (++i < (len - len / 2))
		push_a(a, b, ops);
	return (*a);
}

t_stack	*quicksort_b(t_stack **a, t_stack **b, t_list **ops, size_t len)
{
	int		pivot;
	size_t	i;
	t_list	*tmp;
	char	full_stack;

	full_stack = (len == (size_t) ft_lstsize((*b)->top));
	if (len <= 1 || ft_lst_issort_n((*b)->top, len, -1))
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
	while (!full_stack && ++i < len - len / 2)
		rrotate_b(b, ops);
	quicksort_b(a, b, ops, (len  - len / 2));
	quicksort_a(a, b, ops, len / 2);
	i = -1;
	while (++i < (len / 2))
		 push_b(a, b, ops);
	return (*b);
}
