/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_3_mixed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:32:47 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/10 19:46:34 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	norm_master4(t_node **a, t_node **b, t_nums *nums)
{
	int	aa;
	int	bb;
	int	cc;

	aa = (*a)->next->num;
	bb = (*a)->next->next->num;
	cc = (*a)->next->next->next->num;
	if (aa > bb && aa > cc && bb > cc)
	{
		cmd(a, b, PB);
		cmd(a, b, SA);
		cmd(a, b, RA);
		cmd(a, b, RA);
		nums->i = 2;
		cmd(a, b, PA);
	}
}

static void	norm_master3(t_node **a, t_node **b, t_nums *nums)
{
	int	aa;
	int	bb;
	int	cc;

	aa = (*a)->next->num;
	bb = (*a)->next->next->num;
	cc = (*a)->next->next->next->num;
	if (aa > bb && aa > cc && bb < cc)
	{
		cmd(a, b, SA);
		cmd(a, b, RA);
		nums->i = 1;
		cmd(a, b, SA);
	}
	else
		norm_master4(a, b, nums);
}

static void	norm_master2(t_node **a, t_node **b, t_nums *nums)
{
	int	aa;
	int	bb;
	int	cc;

	aa = (*a)->next->num;
	bb = (*a)->next->next->num;
	cc = (*a)->next->next->next->num;
	if (aa < bb && aa > cc && bb > cc)
	{
		cmd(a, b, PB);
		cmd(a, b, SA);
		cmd(a, b, RA);
		nums->i = 1;
		cmd(a, b, PA);
	}
	else
		norm_master3(a, b, nums);
}

static void	norm_master1(t_node **a, t_node **b, t_nums *nums)
{
	int	aa;
	int	bb;
	int	cc;

	aa = (*a)->next->num;
	bb = (*a)->next->next->num;
	cc = (*a)->next->next->next->num;
	if (aa < bb && aa < cc && bb > cc)
	{
		cmd(a, b, RA);
		nums->i = 1;
		cmd(a, b, SA);
	}
	else if (aa > bb && aa < cc && bb < cc)
		cmd(a, b, SA);
	else
		norm_master2(a, b, nums);
}

void	sort_3_mixed(t_node **a, t_node **b, t_nums *nums)
{
	int	aa;
	int	bb;
	int	cc;

	nums->i = 0;
	aa = (*a)->next->num;
	bb = (*a)->next->next->num;
	cc = (*a)->next->next->next->num;
	if (nums->stackamount == 2)
	{
		if ((*a)->next->num > (*a)->next->next->num)
			cmd(a, b, SA);
	}
	else if (nums->stackamount == 3)
		norm_master1(a, b, nums);
	while (++(nums->i) <= nums->stackamount)
		cmd(a, b, RA);
}
