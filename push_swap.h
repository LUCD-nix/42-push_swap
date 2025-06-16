/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:03:10 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/25 14:03:18 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
}	t_stack;

// TODO : refactor a bit
void	do_nothing(void	*a);
void	ft_sort_int_tab(int *tab, int size);
int		ft_lstmedian(t_list *lst, size_t size);
t_list	*prune_iter(t_list	**ops);

t_stack	*rotate_a(t_stack **a, t_list **ops);
t_stack	*rrotate_a(t_stack **a, t_list **ops);

t_stack	*rotate_b(t_stack **b, t_list **ops);
t_stack	*rrotate_b(t_stack **b, t_list **ops);

t_stack	*push_a(t_stack **a, t_stack **b, t_list **ops);
t_stack	*push_b(t_stack **a, t_stack **b, t_list **ops);

t_stack	*quicksort_a(t_stack **a, t_stack **b, t_list **ops, size_t len);
t_stack	*quicksort_b(t_stack **a, t_stack **b, t_list **ops, size_t len);

void	ft_lstremove2_and_join(t_list **first, t_list **to_del,
			void (*del)(void*));
void	ft_lstremove2_and_replace(t_list **first, t_list **to_del,
			void (*del)(void*), char *to_add);

t_stack	*sort_2a(t_stack **a, t_list **ops);
t_stack	*sort_2b(t_stack **b, t_list **ops);

#endif // PUSH_SWAP_H
