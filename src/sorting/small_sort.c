/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:46:05 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/05 17:48:17by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	not_sorted(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	if (*b)
		return (1);
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	not_sorted_a(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sort_3(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		sa(*a);
		return ;
	}
	while (not_sorted(a, b))
	{
		if ((*a)->next->index == 0 && (*a)->index == 1)
			sa(*a);
		else if ((*a)->index == 0)
		{
			pb(a, b);
			ra(a);
			pa(b, a);
		}
		else
			ra(a);
	}
}

int	at_end(int index, t_stack **head)
{
	t_stack	*temp;

	temp = last_node(head);
	if (temp->index == index)
		return (1);
	return (0);
}

int	is_in_end(t_stack **lst, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(*lst);
	while (i <= size / 2)
	{
		if ((*lst)->index == index)
			return (0);
		lst = &(*lst)->next;
		i++;
	}
	return (1);
}

int	ft_lst_size(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	tmp = lst;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

void	sort_5(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = 0;
	(void)len;
	while (not_sorted_a(a))
	{
		if ((*a)->index == i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->next->index == i)
			sa(*a);
		else if (at_end(i, a))
			rra(a);
		else
			ra(a);
	}
	while (*b)
		pa(b, a);
}
