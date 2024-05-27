/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:17:15 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/12 15:12:13 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

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
	struct s_nums	*small;
	struct s_nums	*midium;
	struct s_nums	*large;
	int				first;
	int				s_min;
	int				s_max;
	int				m_min;
	int				m_max;
	int				l_min;
	int				l_max;
	int				stackamount;
	int				i;
	int				flag;
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

//check_args
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(char *s);
char	*ft_strjoin_pushswap(char *s1, char *s2);
char	**check_if_split(char **argv, int *argc);
void	check_args(t_presort *l, int argc, char **argv);
void	arr2node(t_node **a, t_presort *l, int argc);
void	pushswap(t_node **a, t_node **b, int argc);
void	sort_3_mixed(t_node **a, t_node **b, t_nums *nums);
void	push_swap_chore(t_node **a, t_node **b, t_nums nums);
void	pushswap(t_node **a, t_node **b, int argc);
void	pushswap1(t_node **a, t_node **b, t_nums *n);
void	creat_bunch_of_num(t_nums **n);
void	set_bunch(t_nums **n, t_nums *sma, t_nums *mid, t_nums *big);
void	check_if_sorted(t_node **a);
//9_error
void	finisher(void);
void	free_nums(long *nums1, long *nums2);
void	free_stack(t_node **stack1, t_node **stack2);
void	check(t_node **a, t_node **b);
//cmd
void	cmd(t_node **a, t_node **b, int i);
void	swap(t_node **a, int i);
void	swaps(t_node **a, t_node **b);
void	push(t_node **from, t_node **to, int i);
void	rotate(t_node **a, int i);
void	rotater(t_node **a, t_node **b);
void	r_rotate(t_node **a, int i);
void	r_rotater(t_node **a, t_node **b);
//sort for less than 5
void	less_than_3_only(t_node **a, int c);
void	a_less_than_6_only(t_node **a, t_node **b);

#endif