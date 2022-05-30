/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:53:51 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/29 19:54:21 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	reverse_rotate(t_stack **head)
{
	t_stack	*temp;
	int	temp_data;
	int	temp_index;

	if (!*head || !(*head)->next)
		return (1);
	temp = last_node(head);
	while (temp->prev)
	{
		temp_index = temp->index;
		temp_data = temp->data;
		temp->index = temp->prev->index;
		temp->data = temp->prev->data;
		temp->prev->data = temp_data;
		temp->prev->index = temp_index;
		temp = temp->prev;
	}
	return (0);
}

int	rra(t_stack **head)
{
	if (!reverse_rotate(head))
		ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_stack **head)
{
	if (!reverse_rotate(head))
		ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_stack **head_a, t_stack **head_b)
{
	int	a;

	a = 0;
	if (!reverse_rotate(head_a))
		a++;
	if (!reverse_rotate(head_b))
		a++;
	if (a > 0)
		ft_putstr_fd("rrr\n", 1);
	return (0);
}
