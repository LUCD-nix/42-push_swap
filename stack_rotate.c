/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:41 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:52 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*rotate_a(t_stack **a, t_stack **b, t_list **ops)
{
	(*a)->bottom->next = (*a)->top;
	(*a)->bottom = (*a)->top;
	(*a)->top = (*a)->top->next;
	(*a)->bottom->next = NULL;
	add_op_or_exit("ra", a, b, ops);
	return (*a);
}

t_stack	*rotate_b(t_stack **a, t_stack **b, t_list **ops)
{
	(*b)->bottom->next = (*b)->top;
	(*b)->bottom = (*b)->top;
	(*b)->top = (*b)->top->next;
	(*b)->bottom->next = NULL;
	add_op_or_exit("rb", a, b, ops);
	return (*b);
}

t_stack	*rrotate_a(t_stack **a, t_stack **b, t_list **ops)
{
	t_list	*tmp;

	tmp = (*a)->top;
	if ((*a)->top != (*a)->bottom)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		(*a)->bottom->next = (*a)->top;
		(*a)->top = (*a)->bottom;
		(*a)->bottom = tmp;
		tmp->next = NULL;
		add_op_or_exit("rra", a, b, ops);
	}
	return (*a);
}

t_stack	*rrotate_b(t_stack **a, t_stack **b, t_list **ops)
{
	t_list	*tmp;

	tmp = (*b)->top;
	if ((*b)->top != (*b)->bottom)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		(*b)->bottom->next = (*b)->top;
		(*b)->top = (*b)->bottom;
		(*b)->bottom = tmp;
		tmp->next = NULL;
		add_op_or_exit("rrb", a, b, ops);
	}
	return (*b);
}
