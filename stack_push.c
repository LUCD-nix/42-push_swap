/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:41 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:52 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*sort_2a(t_stack **a, t_list **ops)
{
	t_list	*first;
	t_list	*second;
	int		*tmp;

	first = (*a)->top;
	second = (*a)->top->next;
	if (*(int *) first->content > *(int *) second->content)
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
	if (*(int *) first->content < *(int *) second->content)
	{
		tmp = first->content;
		first->content = second->content;
		second->content = tmp;
		ft_lstadd_back(ops, ft_lstnew("sb"));
	}
	return (*b);
}

t_stack	*push_a(t_stack **a, t_stack **b, t_list **ops)
{
	t_list	*tmp;

	tmp = (*a)->top;
	(*a)->top = (*b)->top;
	(*b)->top = (*b)->top->next;
	(*a)->top->next = tmp;
	if (!(*a)->bottom)
		(*a)->bottom = (*a)->top;
	ft_lstadd_back(ops, ft_lstnew("pa"));
	return (*a);
}

t_stack	*push_b(t_stack **a, t_stack **b, t_list **ops)
{
	t_list	*tmp;

	tmp = (*b)->top;
	(*b)->top = (*a)->top;
	(*a)->top = (*a)->top->next;
	(*b)->top->next = tmp;
	if (!(*b)->bottom)
		(*b)->bottom = (*b)->top;
	ft_lstadd_back(ops, ft_lstnew("pb"));
	return (*b);
}
