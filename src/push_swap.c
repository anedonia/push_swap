/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:39:40 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/03 15:27:30 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_err(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	ft_err_spe(char **ptr)
{
	ft_free_char(ptr);
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
	if (argc == 2 && argv[1] && ft_strchr(argv[1], ' '))
		argc = spe_parsing(argv[1], &head_a) + 1;
	else
		parsing(&argv[1], argc - 1, &head_a);
	sort_index(&head_a);
	sort_radix(&head_a, &head_b, argc - 1);
	//print_list(&head_a);
	ft_free(&head_a);
}
//il faut en dessous de 1100 pour 100 params 
//et en dessous de 7k pour 500 et t'auras la note min
