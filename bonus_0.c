/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:04:52 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/14 13:59:05 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = ft_strlen(src);
	return (i);
}

int	ft_strlen(char *s)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin_pushswap(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ans;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (len == 0)
		finisher();
	ans = (char *)malloc(sizeof(char) * (len + 2));
	if (!ans)
		finisher();
	i = 0;
	while (s1 && s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i++] = ' ';
	j = -1;
	while (s2 && s2[++j])
		ans[i + j] = s2[j];
	ans[i + j] = '\0';
	return (ans);
}

static void	norm_master(t_node **b)
{
	(*b)->num = 0;
	(*b)->next = *b;
	(*b)->prev = *b;
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_presort	l;

	if (argc == 2)
		argv = check_if_split(argv, &argc);
	if (argc == 1)
		exit(1);
	check_args(&l, argc, argv);
	if (argc == 2)
		exit(0);
	a = (t_node *)malloc(sizeof(t_node));
	if (a == NULL)
		finisher();
	a->next = NULL;
	arr2node(&a, &l, argc);
	b = (t_node *)malloc(sizeof(t_node));
	if (b == NULL)
		finisher();
	norm_master(&b);
	checker(&a, &b, argc);
}
