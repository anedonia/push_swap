/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:08:26 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/31 20:26:01 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_free(t_stack **head)
{
	t_stack	*temp;

	if (!head)
		return ;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	free(*head);
}
