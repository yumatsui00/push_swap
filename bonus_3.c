/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:09:32 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/17 23:39:13 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"
#include "get_next_line.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		n--;
		s1++;
		s2++;
	}
	if (n > 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}

static int	error_or_finish(char c)
{
	if (c == '\n')
		return (1);
	else
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	return (0);
}

static int	check_cmd(t_node **a, t_node **b, char *buff)
{
	if (ft_strncmp("pa\n", buff, 4) == 0)
		cmd(a, b, PA);
	else if (ft_strncmp("pb\n", buff, 4) == 0)
		cmd(a, b, PB);
	else if (ft_strncmp("sa\n", buff, 4) == 0)
		cmd(a, b, SA);
	else if (ft_strncmp("sb\n", buff, 4) == 0)
		cmd(a, b, SB);
	else if (ft_strncmp("ss\n", buff, 4) == 0)
		cmd(a, b, SS);
	else if (ft_strncmp("ra\n", buff, 4) == 0)
		cmd(a, b, RA);
	else if (ft_strncmp("rb\n", buff, 4) == 0)
		cmd(a, b, RB);
	else if (ft_strncmp("rr\n", buff, 4) == 0)
		cmd(a, b, RR);
	else if (ft_strncmp("rra\n", buff, 5) == 0)
		cmd(a, b, RRA);
	else if (ft_strncmp("rrb\n", buff, 5) == 0)
		cmd(a, b, RRB);
	else if (ft_strncmp("rrr\n", buff, 5) == 0)
		cmd(a, b, RRR);
	else
		return (error_or_finish(*buff));
	return (0);
}

static void	checker2(t_node **a, t_node **b, int argc)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if ((*a)->num != i)
		{
			write(2, "KO\n", 3);
			exit(1);
		}
		(*a) = (*a)->next;
	}
	if ((*a)->num != 0)
		write(2, "KO\n", 3);
	else if ((*b)->next->num != 0 || (*b)->prev->num != 0)
		write(2, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	checker(t_node **a, t_node **b, int argc)
{
	char	*buff;

	buff = NULL;
	while (1)
	{
		if (get_next_line(0, &buff) == 0)
		{
			checker2(a, b, argc);
			exit(0);
		}
		if (check_cmd(a, b, buff) == 1)
			break ;
		free(buff);
	}
	checker2(a, b, argc);
	exit(0);
}
