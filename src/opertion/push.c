/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:17:42 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/31 20:28:56 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push_empty(t_stack **source, t_stack **target)
{
	if (!*target)
	{
		*target = *source;
		(*target)->next = NULL;
	}
	else
	{
		(*target)->prev = *source;
		(*target)->prev->next = *target;
		*target = (*target)->prev;
	}
	*source = NULL;
	return (0);
}

int	push(t_stack **source, t_stack **target)
{
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
	if (*source)
	{
		if ((*source)->next)
			push(source, target);
		else
			push_empty(source, target);
		ft_putstr_fd("pa\n", 1);
		return (0);
	}
	return (4);
}

int	pb(t_stack **source, t_stack **target)
{
	if (*source)
	{
		if ((*source)->next)
			push(source, target);
		else
			push_empty(source, target);
		ft_putstr_fd("pb\n", 1);
		return (0);
	}
	return (4);
}
