/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_9_control2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:11:02 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/09 22:10:33 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	rotater(t_node **a, t_node **b)
{
	t_node	*tmp;

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

void	r_rotate(t_node **a)
{
	t_node	*tmp;

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
