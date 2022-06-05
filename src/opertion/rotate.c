/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:45:30 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/05 19:49:23 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rotate(t_stack **head)
{
	t_stack	*temp;
	int		temp_data;
	int		temp_index;

	if (!*head || !(*head)->next)
		return (1);
	temp = *head;
	while (temp->next)
	{
		temp_data = temp->data;
		temp_index = temp->index;
		temp->data = temp->next->data;
		temp->index = temp->next->index;
		temp->next->data = temp_data;
		temp->next->index = temp_index;
		temp = temp->next;
	}
	return (0);
}

int	ra(t_stack **head)
{
	if (!rotate(head))
		ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_stack **head)
{
	if (!rotate(head))
		ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rr(t_stack **head_a, t_stack **head_b)
{
	int	a;

	a = 0;
	if (!rotate(head_a))
		a++;
	if (!rotate(head_b))
		a++;
	if (a > 0)
		ft_putstr_fd("rr\n", 1);
	return (0);
}
