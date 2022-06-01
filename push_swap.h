/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:14:34 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/01 11:55:51 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft-main/libft.h"
# include <limits.h> //macro pour int max
# include <unistd.h> //macro pour stderr
# include <stdio.h> //a enlever

// typedef	struct s_tab
// {
// } t_tab;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
	int				index;

}	t_stack;

int		swap(t_stack *head);
int		sb(t_stack *head);
int		sa(t_stack *head);
int		ss(t_stack *head_a, t_stack *head_b);
int		push(t_stack **source, t_stack **target);
int		push_empty(t_stack **source, t_stack **target);
int		pa(t_stack **source, t_stack **target);
int		pb(t_stack **source, t_stack **target);
int		rotate(t_stack **head);
int		ra(t_stack **head);
int		rb(t_stack **head);
int		rr(t_stack **head_a, t_stack **head_b);
int		reverse_rotate(t_stack **head);
int		rra(t_stack **head);
int		rrb(t_stack **head);
int		rrr(t_stack **head_a, t_stack **head_b);
t_stack	*last_node(t_stack **head);
void	ft_free(t_stack **head);
t_stack	*create_node(int data, int index);
void	print_list(t_stack **head);
int		ft_add_front(int data, t_stack **head);
int		ft_add_back(int data, t_stack **head);
int		fill_list(int *tab, t_stack **head, int argc);
int		check_argv(char **argv);
int		ft_atoi_tuning(const char *nptr);
int		law_n_order(int *tab, int argc);
int		order(int *tab, int argc);
void	parsing(char **argv, int argc, t_stack **head);
void	ft_err(void);
void	sort_index(t_stack **head);
int		find_index(t_stack **head, int nb);
void	sort_radix(t_stack **a, t_stack **b, int size);
#endif