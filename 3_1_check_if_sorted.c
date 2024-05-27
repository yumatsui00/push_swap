/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_check_if_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:14:54 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/10 16:25:08 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_if_sorted(t_node **a)
{
	int		flag;
	int		i;
	t_node	*first;

	flag = 0;
	i = 1;
	first = (*a);
	(*a) = (*a)->next;
	while ((*a)->num != 0)
	{
		if ((*a)->num == i)
			flag = 1;
		else
		{
			flag = 0;
			break ;
		}
		(*a) = (*a)->next;
		i++;
	}
	if (flag == 0)
		(*a) = first;
	else
		exit(1);
}
