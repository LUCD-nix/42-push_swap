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

// the content of ops is never malloced so this is fine
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
		if ((!ft_strcmp(content, "pa") && !ft_strcmp(next, "pb"))
		|| (!ft_strcmp(content, "pb") && !ft_strcmp(next, "pa"))
		|| (!ft_strcmp(content, "ra") && !ft_strcmp(next, "rra"))
		|| (!ft_strcmp(content, "rra") && !ft_strcmp(next, "ra"))
		|| (!ft_strcmp(content, "rb") && !ft_strcmp(next, "rrb"))
		|| (!ft_strcmp(content, "rrb") && !ft_strcmp(next, "rb"))
		|| (!ft_strcmp(content, "sa") && !ft_strcmp(next, "sa"))
		|| (!ft_strcmp(content, "sb") && !ft_strcmp(next, "sb")))
			ft_lstremove2_and_join(ops, &cursor, &do_nothing);
		else if ((!ft_strcmp(content, "ra") && !ft_strcmp(next, "rb"))
			|| (!ft_strcmp(content, "rb") && !ft_strcmp(next, "ra")))
			ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "rr");
		else if ((!ft_strcmp(content, "rra") && !ft_strcmp(next, "rrb"))
			|| (!ft_strcmp(content, "rrb") && !ft_strcmp(next, "rrb")))
			ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "rrr");
		// else if ((!ft_strcmp(content, "sa") && !ft_strcmp(next, "sb"))
		// 	|| (!ft_strcmp(content, "sb") && !ft_strcmp(next, "sa")))
		// 	ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "ss");
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
		old = ft_lstsize(*ops);
		new = prune_ops(ops);
	}
	return (*ops);
}
