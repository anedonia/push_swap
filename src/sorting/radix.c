/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:53:47 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/31 20:42:47 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_radix(t_stack **a, t_stack **b, int size)
{
	int	max_bit;
	int	max_size;
	int	i;
	int	j;

	max_bit = 0;
	max_size = size -1;
	i = 0;
	while ((max_size >> max_bit) != 0)
		max_bit++;
	while (i < max_bit)
	{
		j = 0;
		while ((j < size))
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(b, a);
		i++;
	}
}
