/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_dsort2_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:32:34 by ngenadie          #+#    #+#             */
/*   Updated: 2021/10/30 19:34:42 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

uint64_t	ft_lowest_index(t_dynarray *darr)
{
	uint64_t	i;
	int			*tab;
	uint64_t	index;
	int			nb;

	i = 0;
	index = 0;
	tab = darr->list;
	nb = tab[0];
	while (i < darr->nb_cells)
	{
		if (tab[i] < nb)
		{
			nb = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

uint64_t	ft_highest_index(t_dynarray *darr)
{
	uint64_t	i;
	int			*tab;
	uint64_t	index;
	uint64_t	index2;
	int			nb;

	i = 0;
	index = 0;
	index2 = 0;
	tab = darr->list;
	nb = tab[0];
	while (i < darr->nb_cells)
	{
		if (tab[i] > nb)
		{
			nb = tab[i];
			index2 = index;
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_fast_sort3(t_dynarray *darr, bool cmprt)
{
	int	*tab;

	tab = (int *)darr->list;
	if (tab[0] < tab[1] && tab[0] < tab[2])
	{
		if (tab[1] > tab[2])
		{
			ft_rrs(darr, 1, cmprt);
			ft_sw(darr, cmprt);
		}
	}
	return (0);
}

int	ft_fast_sort2(t_dynarray *darr, bool cmprt)
{
	int	*tab;

	tab = (int *)darr->list;
	if (tab[2] < tab[0] && tab[2] < tab[1])
	{
		if (tab[0] < tab[1])
			ft_rrs(darr, 1, cmprt);
		else
		{
			ft_sw(darr, cmprt);
			ft_rrs(darr, 1, cmprt);
		}
	}
	else
		return (ft_fast_sort3(darr, cmprt));
	return (0);
}

int	ft_fast_sort(t_dynarray *darr, bool cmprt)
{
	int	*tab;

	tab = (int *)darr->list;
	if (tab[1] < tab[0] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])
			ft_sw(darr, cmprt);
		else
			ft_rs(darr, 1, cmprt);
	}
	else
		return (ft_fast_sort2(darr, cmprt));
	return (0);
}
