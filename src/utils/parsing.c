/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:57:02 by ldevy             #+#    #+#             */
/*   Updated: 2022/05/31 20:43:50 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				ft_err();
			if (argv[i][j] == '-' && j != 0)
				ft_err();
			if (argv[i][j] == '-' && j == 0 && !ft_isdigit(argv[i][j + 1]))
				ft_err();
			j++;
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
	res = res * signe;
	if (res > INT_MAX || res < INT_MIN)
		ft_err();
	return (res);
}

int	law_n_order(int *tab, int argc)
{
	int	i;
	int	j;
	int	order_;
	int	law;

	i = 0;
	law = 0;
	while (argc > i)
	{
		j = 0;
		while (argc > j)
		{
			if (tab[i] == tab[j] && i != j)
				law = 1;
			j++;
		}
		i++;
	}
	order_ = order(tab, argc);
	if (law || order_)
		return (1);
	return (0);
}

int	order(int *tab, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			i = 0;
			break ;
		}
		i++;
	}
	if (i != 0)
		return (1);
	return (0);
}

void	parsing(char **argv, int argc, t_stack **head)
{
	int	i;
	int	*tab;

	check_argv(argv);
	tab = malloc(sizeof(*tab) * argc);
	i = 0;
	while (argv[i])
	{
		tab[i] = ft_atoi_tuning(argv[i]);
		i++;
	}
	if (law_n_order(tab, argc))
	{
		free(tab);
		ft_err();
	}
	fill_list(tab, head, argc);
	free(tab);
}
//si cest deja dans lordre pas d'erreur