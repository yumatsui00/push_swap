/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_control1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:10:36 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/09 20:44:10 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_node **a, int i)
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
	if (i == SA)
		write(1, "sa\n", 3);
	if (i == SB)
		write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
}

void	push(t_node **from, t_node **to, int i)
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
	if (i == PA)
		write(1, "pa\n", 3);
	else if (i == PB)
		write(1, "pb\n", 3);
}

void	rotate(t_node **a, int i)
{
	t_node	*tmp;

	if (i == RA)
		write(1, "ra\n", 3);
	else if (i == RB)
		write(1, "rb\n", 3);
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
		swap(a, SA);
	else if (i == SB)
		swap(b, SB);
	else if (i == SS)
		swaps(a, b);
	else if (i == PA)
		push(b, a, PA);
	else if (i == PB)
		push(a, b, PB);
	else if (i == RA)
		rotate(a, RA);
	else if (i == RB)
		rotate(b, RB);
	else if (i == RR)
		rotater(a, b);
	else if (i == RRA)
		r_rotate(a, RRA);
	else if (i == RRB)
		r_rotate(b, RRB);
	else if (i == RRR)
		r_rotater(a, b);
}
