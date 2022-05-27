/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:19:28 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/25 16:22:13 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //pour le testing

t_stack	*create_node(int data, int index)
{
	t_stack	*new;

	//new = ft_calloc(1, sizeof(t_stack));
	new = malloc(sizeof(t_stack));	//a changer pour une ft maison
	if (!new)
		return (NULL);    //si return null commet appeler la fonction d'erreur ?
	new->data = data;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

void    print_list(t_stack **head)
{
	t_stack *current = *head;
	t_stack	*previous;
	while (current != NULL)
	{
		printf("element number    : %d \n", current->data);
		//printf("prev element addr : %p \n", current->prev);
		previous = current->prev;
		current = current->next;
		if (previous != NULL)
			printf("previous element number : %d \n", previous->data);
		else 
			printf("no previous element \n");
	}
	
}

int	ft_add_front(int data, t_stack **head)
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

int	fill_list(int *tab, t_stack **head)
{
	int     i;

	for (i = 0; i < 10; i++)
	{
		//ft_add_front(tab[i], head);
		ft_add_back(tab[i], head);
	}
	return (0);	
}


int main(void)
{
	t_stack *head;
	int tab[10] = {1,2,3,4,5,6,7,8,9,0};
	
	head = NULL;
	fill_list(tab, &head);
	print_list(&head);
	return (0);
}
//on a pas besoin de malloc une liste de taille n etc on initialise les elements quand on les a
//on va avoir une head qui aura un prev null 
//on alloue de la memoire uniquement quand un node est cree
//
