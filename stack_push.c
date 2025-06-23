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

void	add_op_or_exit(const char *op,
			t_stack **stack1, t_stack **stack2, t_list **ops)
{
	t_list	*to_add;

	to_add = NULL;
	to_add = ft_lstnew((void *)op);
	if (!to_add)
		exit_error_sort_malloc(stack1, stack2, ops);
	ft_lstadd_back(ops, to_add);
}

t_stack	*sort_2a(t_stack **a, t_stack **b, t_list **ops)
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
		add_op_or_exit("sa", a, b, ops);
	}
	return (*a);
}

t_stack	*sort_2b(t_stack **a, t_stack **b, t_list **ops)
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
		add_op_or_exit("sb", a, b, ops);
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
	add_op_or_exit("pa", a, b, ops);
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
	add_op_or_exit("pb", a, b, ops);
	return (*b);
}
