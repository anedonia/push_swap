/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:39:40 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/01 01:28:04 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_err(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		exit (1);
	parsing(&argv[1], argc - 1, &head_a);
	sort_index(&head_a);
	sort_radix(&head_a, &head_b, argc - 1);
	//print_list(&head_a);
	ft_free(&head_a);
}

//tester les operations 
//faire l'indexage simple