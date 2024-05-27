/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:07:52 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/09 21:08:05 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static void	ft_stackadd_back(t_node **a, t_presort *l, t_node *first)
{
	t_node	*new;
	t_node	*last;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		while (first != NULL)
		{
			last = first->next;
			free(first);
			first = last;
		}
		free_nums(l->num_compressed, NULL);
	}
	new->next = NULL;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	arr2node(t_node **a, t_presort *l, int argc)
{
	int		i;
	t_node	*first;
	t_node	*last;

	(*a)->num = 0;
	first = (*a);
	i = -1;
	while (++i < argc - 1)
	{
		ft_stackadd_back(a, l, first);
		last = (*a)->next;
		last->prev = (*a);
		last->num = l->num_compressed[i];
		(*a) = last;
	}
	last->next = first;
	first->prev = last;
	free(l->num_compressed);
	(*a) = first;
}
