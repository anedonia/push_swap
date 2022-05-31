/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:21:02 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/31 20:28:28 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_index(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	while (temp)
	{
		temp->index = find_index(head, temp->data);
		temp = temp->next;
	}
}

int	find_index(t_stack **head, int nb)
{
	t_stack	*temp;
	int		i;

	temp = *head;
	i = 0;
	while (temp)
	{
		if (temp->data < nb)
			i++;
		temp = temp->next;
	}
	return (i);
}
