/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_control2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:11:02 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/09 22:07:01 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotater(t_node **a, t_node **b)
{
	t_node	*tmp;

	write(1, "rr\n", 3);
	while ((*a)->num != 0)
		(*a) = (*a)->next;
	if ((*a)->next->next->num == 0)
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	(*a)->next->prev = *a;
	tmp->prev = (*a)->prev;
	(*a)->prev->next = tmp;
	tmp->next = (*a);
	(*a)->prev = tmp;
	while ((*b)->num != 0)
		(*b) = (*b)->next;
	if ((*b)->next->next->num == 0)
		return ;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	(*b)->next->prev = *b;
	tmp->prev = (*b)->prev;
	(*b)->prev->next = tmp;
	tmp->next = (*b);
	(*b)->prev = tmp;
}

void	r_rotate(t_node **a, int i)
{
	t_node	*tmp;

	if (i == RRA)
		write(1, "rra\n", 4);
	else if (i == RRB)
		write(1, "rrb\n", 4);
	while ((*a)->num != 0)
		(*a) = (*a)->next;
	if ((*a)->next->next->num == 0)
		return ;
	tmp = (*a)->prev;
	(*a)->prev = (*a)->prev->prev;
	(*a)->prev->next = *a;
	tmp->prev = (*a);
	(*a)->next->prev = tmp;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	r_rotater(t_node **a, t_node **b)
{
	t_node	*tmp;

	write(1, "rrr\n", 4);
	while ((*a)->num != 0)
		(*a) = (*a)->next;
	if ((*a)->next->next->num == 0)
		return ;
	tmp = (*a)->prev;
	(*a)->prev = (*a)->prev->prev;
	(*a)->prev->next = *a;
	tmp->prev = (*a);
	(*a)->next->prev = tmp;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	while ((*b)->num != 0)
		(*b) = (*b)->next;
	if ((*b)->next->next->num == 0)
		return ;
	tmp = (*b)->prev;
	(*b)->prev = (*b)->prev->prev;
	(*b)->prev->next = *b;
	tmp->prev = (*b);
	(*b)->next->prev = tmp;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}
