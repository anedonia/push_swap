/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:19:28 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/27 10:34:22by ldevy            ###   ########.fr       */
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
	if (!*head)
	{
		printf("Empty list \n");
		return ;
	}
	while (current != NULL)
	{
		printf("element number    : %d \n", current->data);
		// previous = current->prev;
		current = current->next;
		// if (previous != NULL)
		// 	printf("previous element number : %d \n", previous->data);
		// else 
		// 	printf("no previous element \n");
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

	for (i = 0; i < 9; i++)
	{
		//ft_add_front(tab[i], head);
		ft_add_back(tab[i], head);
	}
	return (0);	
}

t_stack	*last_node(t_stack **head)
{
	t_stack	*last;

	last = *head;
	while (last->next)
		last = last->next;
	return (last);
}

int	reverse_rotate(t_stack **head)
{
	t_stack	*temp;
	int	temp_data;
	int	temp_index;

	if (!*head || !(*head)->next)
		return (1);
	temp = last_node(head);
	while (temp->prev)
	{
		temp_index = temp->index;
		temp_data = temp->data;
		temp->index = temp->prev->index;
		temp->data = temp->prev->data;
		temp->prev->data = temp_data;
		temp->prev->index = temp_index;
		temp = temp->prev;
	}
	return (0);
}

int	rra(t_stack **head)
{
	if (!reverse_rotate(head))
		ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_stack **head)
{
	if (!reverse_rotate(head))
		ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_stack **head_a, t_stack **head_b)
{
	int	a;

	a = 0;
	if (!reverse_rotate(head_a))
		a++;
	if (!reverse_rotate(head_b))
		a++;
	if (a > 0)
		ft_putstr_fd("rrr\n", 1);
	return (0);
}

int main(void)
{
	t_stack *head_a;
	t_stack	*head_b;
	int tab[9] = {1,2,3,4,5,6,7,8,9};
	
	head_a = NULL;
	head_b = NULL;
	fill_list(tab, &head_a); // tester pa pb en fait une des deux
		print_list(&head_a);
		print_list(&head_b);
		printf("\n");
	ra(&head_a);
	ra(&head_a);
	ra(&head_a);
	ra(&head_a);
	ra(&head_a);
	ra(&head_a);
	ra(&head_a);
	ra(&head_a);
	ra(&head_a);

	print_list(&head_a);
	return (0);
}
//on a pas besoin de malloc une liste de taille n etc on initialise les elements quand on les a
//on va avoir une head qui aura un prev null 
//on alloue de la memoire uniquement quand un node est cree
//
