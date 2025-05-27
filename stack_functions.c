/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:41 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:52 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate_a(t_stack *a, t_list *ops)
{
	a->bottom->next = a->top;
	a->bottom = a->top;
	a->top = a->top->next;
	a->bottom->next = NULL;
	ft_lstadd_back(&ops, ft_lstnew("ra"));
	return (a);
}

t_stack	*rotate_b(t_stack *b, t_list *ops)
{
	b->bottom->next = b->top;
	b->bottom = b->top;
	b->top = b->top->next;
	b->bottom->next = NULL;
	ft_lstadd_back(&ops, ft_lstnew("rb"));
	return (b);
}

t_stack	*rrotate_a(t_stack *a, t_list *ops)
{
	t_list	*tmp;

	tmp = a->bottom;
	a->bottom = NULL;
	tmp->next = a->top;
	a->top = tmp;
	a->bottom = ft_lstlast(a->top);
	ft_lstadd_back(&ops, ft_lstnew("rra"));
	return (a);
}

t_stack	*rrotate_b(t_stack *b, t_list *ops)
{
	t_list	*tmp;

	tmp = b->bottom;
	b->bottom = NULL;
	tmp->next = b->top;
	b->top = tmp;
	b->bottom = ft_lstlast(b->top);
	ft_lstadd_back(&ops, ft_lstnew("rrb"));
	return (b);
}

t_stack	*push_a(t_stack *a, t_stack *b, t_list *ops)
{
	t_list	*tmp;

	tmp = a->top->next;
	a->top->next = b->top;
	b->top = a->top;
	a->top = tmp;
	ft_lstadd_back(&ops, ft_lstnew("pa"));
	return (a);
}

// TODO: Both this and push_a are wrong, change with lstadd front and co
t_stack	*push_b(t_stack *a, t_stack *b, t_list *ops)
{
	t_list	*tmp;

	tmp = b->top->next;
	b->top->next = a->top;
	a->top = b->top;
	b->top = tmp;
	ft_lstadd_back(&ops, ft_lstnew("pb"));
	return (b);
}
