/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:14:34 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/23 17:58:05 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft-main/libft.h"
# include <limits.h> //macro pour int max
# include <unistd.h> //macro pour stderr

// typedef	struct s_tab
// {
	
// } t_tab;

typedef struct s_stack
{
	int		data;
	int		index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#endif