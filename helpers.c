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

int	ft_lstmedian(t_list *lst, size_t size)
{
	int		*arr;
	size_t	i;

	arr = ft_calloc(sizeof(int), size);
	if (!arr)
		return (0);
	i = -1;
	while (++i < size && lst)
	{
		arr[i] = *((int *)lst->content);
		lst = lst->next;
	}
	ft_sort_int_tab(arr, size);
	return (arr[size / 2 - !(size % 2)]);
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
