/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:39:40 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/30 18:13:55 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_err(void)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack *head_a;
	//t_stack	*head_b;
	
	head_a = NULL;
	//head_b = NULL;
	
	if (argc == 1)
		exit (1);
	parsing(&argv[1], argc-1, &head_a);
	//sort_index();
	print_list(&head_a);
}





//je me demande comment faire implémenter radix avec des stacks 
//je dois coder les swaps reverse etc ...
//coder une forme de sort 
//initialiser les deux stacks
//check la data fournie 
//commencer par sort sans les signes 
//faire un index 
