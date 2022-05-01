/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:39:40 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/01 19:22:45 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err()
{
	ft_putstr_fd("Error", STDERR_FILENO);
	exit(1);
}

void	check_argv(argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				ft_err();
		}
		i++;
	}
	i = 0;
	while (argv[i])
		ft_atoi_tuning(argv[i++]);
}

int	ft_atoi_tuning(const char *nptr)
{
	long	res;
	int		i;
	long	signe;

	signe = 1;
	i = 0;
	res = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	if (res > INT_MAX || res < INT_MIN)
		ft_err();
	return (res * signe);
}

t_list *build_list()
{
	
}

int main(int argc, char **argv)
{
	t_list a;
	t_list b;
	
	if (argc == 1)
		exit (1);
	check_argv(&argv[1]);
	build_list(a);
	check_double();
	
	
}





//je me demande comment faire implémenter radix avec des stacks 
//je dois coder les swaps reverse etc ...
//coder une forme de sort 
//initialiser les deux stacks
//check la data fournie 
//commencer par sort sans les signes 
//