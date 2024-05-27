/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:05:32 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/14 10:33:58 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	long			num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_presort
{
	long	*num_origin;
	long	*num_sorted;
	long	*num_compressed;
}	t_presort;

typedef struct s_nums
{
	int		argc;
	int		pass;
	int		first;
	int		small_min;
	int		small_max;
	int		large_min;
	int		large_max;
	int		stackamount;
	int		i;
	int		flag;
}	t_nums;

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define A 11
# define B 12

int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int size);
char	*ft_strjoin_pushswap(char *s1, char *s2);
char	**check_if_split(char **argv, int *argc);
void	check_args(t_presort *l, int argc, char **argv);
void	arr2node(t_node **a, t_presort *l, int argc);
void	checker(t_node **a, t_node **b, int argc);
void	swap(t_node **a);
void	swaps(t_node **a, t_node **b);
void	push(t_node **from, t_node **to);
void	rotate(t_node **a);
void	cmd(t_node **a, t_node **b, int i);
void	rotater(t_node **a, t_node **b);
void	r_rotate(t_node **a);
void	r_rotater(t_node **a, t_node **b);
void	free_stack(t_node **stack1, t_node **stack2);
void	free_nums(long *nums1, long *nums2);
void	finisher(void);

#endif