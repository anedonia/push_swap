/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:14:30 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/27 11:15:21 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap(t_stack *head)
{
	int	temp_index;
	int	temp_data;

	if (!head || !head->next)
		return (1);
	temp_data = head->data;
	temp_index = head->index;
	head->data = head->next->data;
	head->index = head->next->index;
	head->next->data = temp_data;
	head->next->index = temp_index;
	return (0);
}

int	sb(t_stack *head)
{
	if (swap(head))
		return (1);
	ft_putstr_fd("sb\n", 1);
	return (0);
}

int	sa(t_stack *head)
{
	if (swap(head))
		return (1);
	ft_putstr_fd("sa\n", 1);
	return (0);
}

int	ss(t_stack *head_a, t_stack *head_b)
{
	if (swap(head_a) || swap(head_b))
		return (1);
	ft_putstr_fd("ss\n", 1);
	return (0);
}
