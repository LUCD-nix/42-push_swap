/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:24 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:34 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	*ps_atoi(void *str)
{
	int	*res;

	res = NULL;
	res = ft_calloc(1, sizeof(int));
	if (!res)
		return (NULL);
	*res = ft_atoi((char *)str);
	return ((void *)res);
}

int	check_input(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	check_input_iter(t_list **strings, char ***temp)
{
	t_list	*cursor;

	cursor = *strings;
	while (cursor)
	{
		if (!check_input((char *)cursor->content))
			exit_error_input_treatment(temp, strings);
		cursor = cursor->next;
	}
}

char	**input_to_heap_array(int argc, char **argv)
{
	char	**res;
	int		i;

	res = NULL;
	if (argc == 2)
		res = ft_split(argv[1], ' ');
	else
	{
		res = ft_calloc(argc, sizeof(char *));
		if (!res)
			exit_error_input_treatment(&res, NULL);
		i = 0;
		while (i + 1 < argc)
		{
			res[i] = ft_strdup(argv[i + 1]);
			if (!res[i])
				exit_error_input_treatment(&res, NULL);
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}
