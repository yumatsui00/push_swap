/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_9_control1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:10:36 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/09 22:10:38 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	swap(t_node **a)
{
	long	tmp;

	while ((*a)->num != 0)
		(*a) = (*a)->next;
	if ((*a)->next->next->num != 0)
	{
		tmp = ((*a)->next->num);
		(*a)->next->num = (*a)->next->next->num;
		(*a)->next->next->num = tmp;
	}
}

void	swaps(t_node **a, t_node **b)
{
	long	tmp;

	while ((*a)->num != 0)
		(*a) = (*a)->next;
	if ((*a)->next->next->num != 0)
	{
		tmp = ((*a)->next->num);
		(*a)->next->num = (*a)->next->next->num;
		(*a)->next->next->num = tmp;
	}
	while ((*b)->num != 0)
		(*b) = (*b)->next;
	if ((*b)->next->next->num != 0)
	{
		tmp = ((*b)->next->num);
		(*b)->next->num = (*b)->next->next->num;
		(*b)->next->next->num = tmp;
	}
}

void	push(t_node **from, t_node **to)
{
	t_node	*tmp;

	while ((*from)->num != 0)
		(*from) = (*from)->next;
	while ((*to)->num != 0)
		(*to) = (*to)->next;
	if ((*from)->next->num == 0)
		return ;
	tmp = (*from)->next;
	(*from)->next = (*from)->next->next;
	(*from)->next->prev = (*from);
	(*to)->next->prev = tmp;
	tmp->next = (*to)->next;
	(*to)->next = tmp;
	tmp->prev = (*to);
}

void	rotate(t_node **a)
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
}

void	cmd(t_node **a, t_node **b, int i)
{
	if (i == SA)
		swap(a);
	else if (i == SB)
		swap(b);
	else if (i == SS)
		swaps(a, b);
	else if (i == PA)
		push(b, a);
	else if (i == PB)
		push(a, b);
	else if (i == RA)
		rotate(a);
	else if (i == RB)
		rotate(b);
	else if (i == RR)
		rotater(a, b);
	else if (i == RRA)
		r_rotate(a);
	else if (i == RRB)
		r_rotate(b);
	else if (i == RRR)
		r_rotater(a, b);
}
