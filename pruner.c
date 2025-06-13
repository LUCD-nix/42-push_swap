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
#include "push_swap.h"

// the content of ops is never malloced so this is fine
void	do_nothing(void *a)
{
	(void)a;
}

static char	can_delete_nodes(char *content, char *next)
{
	if ((!ft_strcmp(content, "pa") && !ft_strcmp(next, "pb"))
		|| (!ft_strcmp(content, "pb") && !ft_strcmp(next, "pa"))
		|| (!ft_strcmp(content, "ra") && !ft_strcmp(next, "rra"))
		|| (!ft_strcmp(content, "rra") && !ft_strcmp(next, "ra"))
		|| (!ft_strcmp(content, "rb") && !ft_strcmp(next, "rrb"))
		|| (!ft_strcmp(content, "rrb") && !ft_strcmp(next, "rb"))
		|| (!ft_strcmp(content, "sa") && !ft_strcmp(next, "sa"))
		|| (!ft_strcmp(content, "sb") && !ft_strcmp(next, "sb")))
		return (1);
	return (0);
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
		if (can_delete_nodes(content, next))
			ft_lstremove2_and_join(ops, &cursor, &do_nothing);
		else if ((!ft_strcmp(content, "ra") && !ft_strcmp(next, "rb"))
			|| (!ft_strcmp(content, "rb") && !ft_strcmp(next, "ra")))
			ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "rr");
		else if ((!ft_strcmp(content, "rra") && !ft_strcmp(next, "rrb"))
			|| (!ft_strcmp(content, "rrb") && !ft_strcmp(next, "rra")))
			ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "rrr");
		else if ((!ft_strcmp(content, "sa") && !ft_strcmp(next, "sb"))
			|| (!ft_strcmp(content, "sb") && !ft_strcmp(next, "sa")))
			ft_lstremove2_and_replace(ops, &cursor, &do_nothing, "ss");
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
