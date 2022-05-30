/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:16:38 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/30 16:40:15 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*create_node(int data, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

void    print_list(t_stack **head) //fnction a enlever ap
{
	t_stack *current = *head;
	if (!*head)
	{
		printf("Empty list \n"); 
		return ;
	}
	while (current != NULL)
	{
		printf("element number    : %d \n", current->data);
		current = current->next;
	}
	
}

int	ft_add_front(int data, t_stack **head) // a enlever
{
	t_stack *new;
	new = create_node(data, 0);
	if (new == NULL)
		return (1);
	if (!*head)
		*head = new;
	else 
	{
		new->next = *head;
		*head = new;
	}
	return (0);
}

int	ft_add_back(int data, t_stack **head)
{
	t_stack *new;
	t_stack	*last;

	new = create_node(data, 0);
	if (!new)
		return (1);
	if (!*head)
	{
		*head = new;
		return (0);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (0);
}

int	fill_list(int *tab, t_stack **head, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_add_back(tab[i], head);
		i++;
	}
	return (0);	
}