/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_a_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:09:46 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/11 12:13:35 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_only_3_rev(t_node **b)
{
	long	aa;
	long	bb;
	long	cc;

	aa = (*b)->next->num;
	bb = (*b)->next->next->num;
	cc = (*b)->next->next->next->num;
	if (aa > bb && aa > cc && bb < cc)
	{
		swap(b, SB);
		rotate(b, RB);
	}
	else if (aa > bb && aa < cc && bb < cc)
		r_rotate(b, RRB);
	else if (aa < bb && aa > cc && bb > cc)
		swap(b, SB);
	else if (aa < bb && aa < cc && bb < cc)
	{
		swap(b, SB);
		r_rotate(b, RRB);
	}
	else if (aa < bb && aa < cc & bb > cc)
		rotate(b, RB);
}

static void	sort_only_3(t_node **a)
{
	long	aa;
	long	bb;
	long	cc;

	aa = (*a)->next->num;
	bb = (*a)->next->next->num;
	cc = (*a)->next->next->next->num;
	if (aa < bb && aa < cc && bb > cc)
	{
		swap(a, SA);
		rotate(a, RA);
	}
	else if (aa > bb && aa < cc && bb < cc)
		swap(a, SA);
	else if (aa < bb && aa > cc && bb > cc)
		r_rotate(a, RRA);
	else if (aa > bb && aa > cc && bb < cc)
		rotate(a, RA);
	else if (aa > bb && aa > cc && bb > cc)
	{
		swap(a, SA);
		r_rotate(a, RRA);
	}
}

void	less_than_3_only(t_node **a, int c)
{
	long	aa;
	long	bb;
	long	cc;

	aa = (*a)->next->num;
	bb = (*a)->next->next->num;
	cc = (*a)->next->next->next->num;
	if (bb == 0)
		return ;
	if (c == A)
	{
		if (cc == 0 && aa > bb)
			swap(a, SA);
		else if (cc != 0)
			sort_only_3(a);
	}
	else if (c == B)
	{
		if (cc == 0 && aa < bb)
			swap(a, SB);
		else if (cc != 0)
			sort_only_3_rev(a);
	}
}

void	a_less_than_6_only(t_node **a, t_node **b)
{
	int		i;
	long	max;

	max = (*a)->next->num;
	(*a) = (*a)->next;
	while ((*a)->num != 0)
	{
		if (max < (*a)->num)
			max = (*a)->num;
		(*a) = (*a)->next;
	}
	i = 0;
	while (++i <= max)
	{
		if (max / 2 >= (*a)->next->num)
			cmd(a, b, PB);
		else
			cmd(a, b, RA);
	}
	less_than_3_only(a, A);
	less_than_3_only(b, B);
	while ((*b)->next->num != 0)
		cmd(a, b, PA);
}
