/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:01:40 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:02:03 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

static void	swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	*point;
	int	*neighbor;

	i = size;
	while (i >= 0)
	{
		j = 0;
		while (j < i - 1)
		{
			point = tab + j;
			neighbor = tab + j + 1;
			if (*point > *neighbor)
				swap(point, neighbor);
			j++;
		}
		i--;
	}
}

int	ft_stack_median(t_stack **stack1, t_stack **stack2, t_list **ops,
		size_t size)
{
	int		*arr;
	int		res;
	t_list	*lst;
	size_t	i;

	lst = (*stack1)->top;
	arr = NULL;
	arr = ft_calloc(sizeof(int), size);
	if (!arr)
		exit_error_sort_malloc(stack1, stack2, ops);
	i = -1;
	while (++i < size && lst)
	{
		arr[i] = *((int *)lst->content);
		lst = lst->next;
	}
	ft_sort_int_tab(arr, size);
	res = arr[size / 2 - !(size % 2)];
	free(arr);
	return (res);
}

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
		if (!new)
		{
			ft_lstclear(first, &do_nothing);
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		cursor->next = new;
		new->next = tmp;
		*to_del = new;
	}
}

void	ft_lstremove2_and_join(t_list **first, t_list **to_del,
							void (*del)(void*))
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
