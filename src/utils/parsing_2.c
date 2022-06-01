/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:57:02 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/01 18:27:55 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	spe_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-') ||
				argv[i][j] == '-' && j != 0 ||
					argv[i][j] == '-' && j == 0 && !ft_isdigit(argv[i][j + 1]))
				ft_err_spe(argv);
			j++;
		}
		i++;
	}
	i = 0;
	while (argv[i])
		ft_atoi_tuning(argv[i++], argv);
}

int	spe_ft_atoi_tuning(const char *nptr, char **argv)
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
		ft_err_spe(argv);
	return (res);
}

int	spe_law_n_order(int *tab, int argc, char **argv)
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
	order_ = spe_order(tab, argc, argv);
	if (law || order_)
		return (1);
	return (0);
}

int	spe_order(int *tab, int argc, char **ptr)
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
	{
		ft_free_char(ptr);
		free(tab);
		exit(1);
	}
	return (0);
}

void	spe_parsing(char *argv, int argc, t_stack **head)
{
	int	i;
	int	*tab;

	spe_check_argv(argv);
	tab = malloc(sizeof(*tab) * argc);
	if (!tab)
		re
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
	ft_free_char(argv);
	free(tab);
}
