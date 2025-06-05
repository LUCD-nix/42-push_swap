/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:02:03 by lucorrei          #+#    #+#             */
/*   Updated: 2025/06/05 14:02:07 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

void	ft_lstremove2_and_replace(t_list **first, t_list **to_del,
							   void (*del)(void*), char *to_add)
{
	t_list	*cursor;
	t_list	*tmp;
	t_list	*new;

	cursor = *first;
	while (cursor->next != *to_del)
		cursor = cursor->next;
	if ((*to_del)->next)
	{
		tmp = (*to_del)->next->next;
		ft_lstdelone((*to_del)->next, del);
		ft_lstdelone((*to_del), del);
		new = ft_lstnew(to_add);
		cursor->next = new;
		new->next = tmp;
		*to_del = new;
	}
}

void	ft_lstremove2_and_join(t_list **first, t_list **to_del, void (*del)(void*))
{
	t_list	*cursor;
	t_list	*tmp;

	cursor = *first;
	while (cursor->next != *to_del)
		cursor = cursor->next;
	if ((*to_del)->next)
	{
		tmp = (*to_del)->next->next;
		ft_lstdelone((*to_del)->next, del);
		ft_lstdelone((*to_del), del);
		cursor->next = tmp;
		*to_del = cursor;
	}
}

// the contents of 
void	do_nothing(void *a)
{
	(void)a;
}
size_t	prune_ops(t_list **ops)
{
	t_list	*cursor;
	char	*content;
	char	*next;

	cursor = *ops;
	while (cursor && cursor->next)
	{
		content = (char *)cursor->content;
		next = (char *)cursor->next->content;
		if ((!ft_strncmp(content, "pa", 2) && !ft_strncmp(next, "pb", 2))
		|| (!ft_strncmp(content, "pb", 2) && !ft_strncmp(next, "pa", 2))
		|| (!ft_strncmp(content, "ra", 2) && !ft_strncmp(next, "rra", 3))
		|| (!ft_strncmp(content, "rra", 3) && !ft_strncmp(next, "ra", 2))
		|| (!ft_strncmp(content, "rb", 2) && !ft_strncmp(next, "rrb", 3))
		|| (!ft_strncmp(content, "rrb", 3) && !ft_strncmp(next, "rb", 2)))
			ft_lstremove2_and_join(ops, &cursor, &do_nothing);
		else if (!ft_strncmp(content, "ra", 3) && !ft_strncmp(next, "rb", 3))
			ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "rr");
		else if (!ft_strncmp(content, "rra", 3) && !ft_strncmp(next, "rrb", 3))
			ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "rrr");
		cursor = cursor->next;
	}
	return (ft_lstsize(*ops));
}
t_list	*prune_iter(t_list	**ops)
{
	size_t	new;
	size_t	old;

	new = 0;
	old = ft_lstsize(*ops);
	while (old > new)
	{
		old = new;
		new = prune_ops(ops);
	}
	return (*ops);
}
