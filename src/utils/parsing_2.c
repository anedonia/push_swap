/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:57:02 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/07 13:38:32 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	spe_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
			|| (argv[i][j] == '-' && j != 0)
			|| (argv[i][j] == '-' && j == 0 && !ft_isdigit(argv[i][j + 1])))
				free_tuning(NULL, argv, 1);
			j++;
		}
		i++;
	}
	i = 0;
	while (argv[i])
	{
		if (!valid_num(argv[i]))
			free_tuning(NULL, argv, 1);
		spe_ft_atoi_tuning(argv[i++], argv);
	}
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
		free_tuning(NULL, argv, 1);
	return (res);
}

void	spe_law_n_order(int *tab, int argc, char **argv)
{
	int	i;
	int	j;
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
	if (law)
		free_tuning(tab, argv, 1);
	spe_order(tab, argc, argv);
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
		free_tuning(tab, ptr, 0);
		exit(1);
	}
	return (0);
}

int	spe_parsing(char *argv, t_stack **head)
{
	int		i;
	int		*tab;
	char	**str;
	int		len;

	str = ft_split(argv, ' ');
	len = arr_len(str);
	spe_check_argv(str);
	tab = malloc(sizeof(*tab) * len);
	if (!tab)
		free_tuning(tab, str, 1);
	i = 0;
	while (str[i])
	{
		tab[i] = ft_atoi_tuning(str[i]);
		i++;
	}
	spe_law_n_order(tab, len, str);
	fill_list(tab, head, len);
	free_tuning(tab, str, 0);
	return (len);
}
