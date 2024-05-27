/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:06:45 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/17 23:32:36 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static long	ft_atol(char *num, t_presort *list)
{
	long	ans;
	int		i;
	int		flag;

	ans = 0;
	i = 0;
	flag = 1;
	if (num[i] == '-')
	{
		i++;
		flag = -1;
	}
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
		{
			free(list->num_origin);
			finisher();
		}
		ans = ans * 10 + ((long)num[i++] - '0');
		if (ans * flag > INT_MAX || ans * flag < INT_MIN)
			free_nums(list->num_origin, NULL);
	}
	return (ans * flag);
}

static long	*ft_numdup(long *num1, int size)
{
	long	*dup;
	long	*ans;
	long	i;

	ans = (long *)malloc(sizeof(long) * size);
	if (!ans)
	{
		free(num1);
		finisher();
	}
	dup = ans;
	i = -1;
	while (++i < size)
		ans[i] = num1[i];
	return (dup);
}

static int	sort_nums(long *nums, long rep)
{
	long	i;
	long	j;
	long	tmp;

	i = -1;
	while (++i < rep - 1)
	{
		j = -1;
		while (++j < rep - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
	i = -1;
	while (++i < rep - 1)
	{
		if (nums[i] == nums[i + 1])
			return (1);
	}
	return (0);
}

static long	*compress_list(t_presort *l, int argc)
{
	long	*nums;
	long	i;
	long	j;

	nums = (long *)malloc(sizeof(long) * (argc - 1));
	if (nums == NULL)
		free_nums(l->num_origin, l->num_sorted);
	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (++j < argc - 1)
		{
			if (l->num_sorted[i] == l->num_origin[j])
				nums[j] = (long)i + 1;
		}
	}
	return (nums);
}

void	check_args(t_presort *l, int argc, char **argv)
{
	long	i;

	l->num_origin = (long *)malloc(sizeof(long) * (argc - 1));
	if (l->num_origin == NULL)
		finisher();
	i = 0;
	while (argv[++i])
		l->num_origin[i - 1] = ft_atol(argv[i], l);
	l->num_sorted = ft_numdup(l->num_origin, argc - 1);
	if (sort_nums(l->num_sorted, argc - 1) == 1)
		free_nums(l->num_origin, l->num_sorted);
	l->num_compressed = compress_list(l, argc);
	free(l->num_origin);
	free(l->num_sorted);
}
