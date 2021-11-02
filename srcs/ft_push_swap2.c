/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:47:12 by ngenadie          #+#    #+#             */
/*   Updated: 2021/11/02 17:05:12 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_error(t_dynarray *darr)
{
	free_dynarray(darr);
	write(2, "Error\n", 6);
	return (-1);
}

int	ft_index_check(t_dynarray darr)
{
	uint64_t	i;
	uint64_t	j;
	int			*tab;

	j = 0;
	i = 0;
	tab = (int *)darr.list;
	while (i < darr.nb_cells)
	{
		j = 0;
		while (j < darr.nb_cells)
		{
			if (tab[i] == tab[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_is_sorted(t_dynarray *darr)
{
	uint64_t	i;

	i = 0;
	while (i < darr->nb_cells)
	{
		if (*(int *)dynacc(darr, i) != (long long)i)
			return (0);
		i++;
	}
	return (1);
}

int	ft_scan(t_dynarray *darr, int old_mid, int mid)
{
	uint64_t	i;
	int			*tab;

	i = 0;
	tab = (int *)darr->list;
	while (i < darr->nb_cells)
	{
		if (tab[i] >= old_mid && tab[i] < mid)
			return (1);
		i++;
	}
	return (0);
}
