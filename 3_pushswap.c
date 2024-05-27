/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_pushswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:45:33 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/14 13:10:05 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_nums(t_nums *n)
{
	n->s_min = n->first;
	n->s_max = n->stackamount / 3 + n->first - 1;
	n->m_min = n->stackamount / 3 + n->first;
	n->m_max = n->stackamount / 3 * 2 + n->first - 1;
	n->l_min = n->stackamount / 3 * 2 + n->first;
	n->l_max = n->stackamount + n->first - 1;
	creat_bunch_of_num(&n);
}

void	push_swap1_1(t_node **a, t_node **b, t_nums *n)
{
	n->i = 0;
	while (++(n->i) <= (n->stackamount))
	{
		if ((*a)->next->num <= n->m_max)
		{
			cmd(a, b, PB);
			if ((*b)->next->num <= n->s_max)
			{
				if ((*a)->next->num > n->m_max && n->i != n->stackamount)
				{
					cmd(a, b, RR);
					n->i++;
				}
				else
					cmd(a, b, RB);
			}
		}
		else
			cmd(a, b, RA);
	}
}

void	push_swap1(t_node **a, t_node **b, t_nums *n)
{
	set_nums(n);
	if (n->stackamount > 3)
	{
		push_swap1_1(a, b, n);
		n->i = n->m_max;
		while (++(n->i) <= n->l_max && n->flag != 0)
			cmd(a, b, RRA);
		n->i = 0;
		while (++(n->i) <= n->m_max)
			cmd(a, b, PA);
		push_swap1(a, b, (n->small));
		push_swap1(a, b, (n->midium));
		push_swap1(a, b, (n->large));
	}
	else
		sort_3_mixed(a, b, n);
}

void	pushswap(t_node **a, t_node **b, int argc)
{
	t_nums	*nums;

	nums = (t_nums *)malloc(sizeof(t_nums));
	if (nums == NULL)
		finisher();
	check_if_sorted(a);
	if (argc <= 4)
		less_than_3_only(a, A);
	else if (argc <= 7)
		a_less_than_6_only(a, b);
	else
	{
		nums->stackamount = argc - 1;
		nums->first = 1;
		nums->flag = 0;
		push_swap1(a, b, nums);
	}
	free(nums);
}
