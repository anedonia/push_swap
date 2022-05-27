/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:17:42 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/27 16:02:07 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int push(t_stack **source, t_stack **target)
{
	//printf("push empty\n");
	if (!*target)
	{
		*target = *source;
		*source = (*source)->next;
		(*target)->next = NULL;
	}
	else
	{
		(*target)->prev = *source;
		*source = (*source)->next;
		(*target)->prev->next = *target;
		(*source)->prev = NULL;
		*target = (*target)->prev;
	}
	return (0);
}

int	pa(t_stack **source, t_stack **target)
{
	if(*source)
	{
		push(source, target);
		//ft_putstr_fd("pa\n", 1);
		return (0);
	}
	return (4);
}

int	pb(t_stack **source, t_stack **target)
{
	if(*source)
	{
		push(source, target);
		ft_putstr_fd("pb\n", 1);
		return (0);
	}
	return (4);
}
