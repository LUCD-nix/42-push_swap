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

static void	ft_sort_int_tab(int *tab, int size)
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
	int	*arr;
	size_t i;

	arr = ft_calloc(sizeof(int), size);
	if (!arr)
		return (0);
	i = -1;
	while (++i < size && lst) // TODO: This will come back to bite me in the ass
	{
		arr[i] = *((int *)lst->content);
		lst = lst->next;
	}
	ft_sort_int_tab(arr, size);
	return (arr[size / 2 - !(size % 2)]);
}
