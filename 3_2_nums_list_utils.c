/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_nums_list_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:49:16 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/10 19:45:48 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_bunch(t_nums **n, t_nums *sma, t_nums *mid, t_nums *big)
{
	(*n)->small = sma;
	(*n)->midium = mid;
	(*n)->large = big;
	(*n)->small->flag = (*n)->flag + 1;
	(*n)->midium->flag = (*n)->flag + 1;
	(*n)->large->flag = (*n)->flag + 1;
	(*n)->small->first = (*n)->first;
	(*n)->small->stackamount = (*n)->s_max - (*n)->s_min + 1;
	(*n)->midium->first = (*n)->m_min;
	(*n)->midium->stackamount = (*n)->m_max - (*n)->m_min + 1;
	(*n)->large->first = (*n)->l_min;
	(*n)->large->stackamount = (*n)->l_max - (*n)->l_min + 1;
}

void	creat_bunch_of_num(t_nums **n)
{
	t_nums	*sma;
	t_nums	*mid;
	t_nums	*big;

	sma = (t_nums *)malloc(sizeof(t_nums));
	if (sma == NULL)
		finisher();
	mid = (t_nums *)malloc(sizeof(t_nums));
	if (mid == NULL)
		finisher();
	big = (t_nums *)malloc(sizeof(t_nums));
	if (big == NULL)
		finisher();
	set_bunch(n, sma, mid, big);
}
