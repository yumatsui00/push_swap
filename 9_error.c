/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:11:24 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/11 12:16:23 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	finisher(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	free_nums(long *nums1, long *nums2)
{
	if (nums1 != NULL)
		free(nums1);
	if (nums2 != NULL)
		free(nums2);
	finisher();
}

void	free_stack(t_node **stack1, t_node **stack2)
{
	t_node	*tmp;

	while (*stack1 != NULL)
	{
		tmp = *stack1;
		(*stack1) = (*stack1)->next;
		free(tmp);
	}
	if (stack2 == NULL)
		return ;
	while ((*stack2)->next != NULL || (*stack2)->next->num == 0)
		(*stack2) = (*stack2)->next;
	while (*stack2 != NULL)
	{
		tmp = (*stack2);
		(*stack2) = (*stack2)->prev;
		free(tmp);
	}
}

// void	check(t_node **a, t_node **b)
// {
// 	printf("stack a\n");
// 	printf("%ld ", (*a)->num);
// 	while ((*a)->next->num != 0)
// 	{
// 		printf("%ld ", (*a)->next->num);
// 		*a = (*a)->next;
// 	}
// 	*a = (*a)->next;
// 	printf("\nstack b\n");
// 	printf("%ld ", (*a)->num);
// 	while ((*b)->next->num != 0)
// 	{
// 		printf("%ld ", (*b)->next->num);
// 		*b = (*b)->next;
// 	}
// 	*b = (*b)->next;
// 	printf("\n");
// }