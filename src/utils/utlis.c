/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:53:09 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/07 15:49:27 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	valid_num(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((str[0] == '-' && len <= 11) || (len <= 10))
		return (1);
	return (0);
}

int	arr_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
