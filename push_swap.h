/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:14:34 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/29 19:55:51 by ldevy            ###   ########.fr       */
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

int	swap(t_stack *head);
int	sb(t_stack *head);
int	sa(t_stack *head);
int	ss(t_stack *head_a, t_stack *head_b);
int push(t_stack **source, t_stack **target);
int	pa(t_stack **source, t_stack **target);
int	pb(t_stack **source, t_stack **target);
int	rotate(t_stack **head);
int	ra(t_stack **head);
int	rb(t_stack **head);
int	rr(t_stack **head);
int	reverse_rotate(t_stack **head);
int	rra(t_stack **head);
int	rrb(t_stack **head);
int	rrr(t_stack **head_a, t_stack **head_b);
#endif