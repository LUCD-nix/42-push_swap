/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:24 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:34 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_strs(char ***temp, t_list **strings)
{
	int	i;

	i = -1;
	while ((*temp)[++i])
		free((*temp)[i]);
	free(*temp);
	*temp = NULL;
	ft_lstclear(strings, &do_nothing);
}

void	free_ops_and_stacks(t_list **ops, t_stack **a, t_stack **b)
{
	ft_lstclear(ops, &do_nothing);
	ft_lstclear(&(*a)->top, &free);
	ft_lstclear(&(*b)->top, &free);
	free(*a);
	free(*b);
	*a = NULL;
	*b = NULL;
}
