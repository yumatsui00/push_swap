/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_if_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:51:31 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/14 13:38:11 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_spchecker(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

static int	ft_spcounter(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_spchecker(s[i], c) == 0 && ft_spchecker(s[i + 1], c) == 1)
			count++;
		i++;
	}
	return (count);
}

static int	string_spliter(char **ans, char *s, char c)
{
	int	start;
	int	end;
	int	count;

	end = 0;
	count = 0;
	while (s[end])
	{
		if (ft_spchecker(s[end], c) == 1)
			end++;
		else
		{
			start = end;
			while (ft_spchecker(s[end], c) == 0)
				end++;
			ans[count] = (char *)malloc(sizeof(char) * (end - start + 1));
			if (!ans)
				finisher();
			ft_strlcpy(ans[count], s + start, end - start + 1);
			count++;
		}
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**ans;
	int		count;

	if (s == NULL)
		finisher();
	count = ft_spcounter(s, c);
	ans = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ans)
		finisher();
	ans[count] = NULL;
	if (!string_spliter(ans, s, c))
		finisher();
	return (ans);
}

char	**check_if_split(char **argv, int *argc)
{
	char	*tmp;
	char	**ans;

	tmp = ft_strjoin_pushswap(argv[0], argv[1]);
	ans = ft_split(tmp, ' ');
	free(tmp);
	*argc = 0;
	while (ans[*argc])
		*argc += 1;
	return (ans);
}
