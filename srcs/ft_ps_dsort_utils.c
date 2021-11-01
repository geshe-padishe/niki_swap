/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_dsort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:01:32 by ngenadie          #+#    #+#             */
/*   Updated: 2021/10/30 19:34:20 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

uint64_t	ft_find_next(uint64_t index_l, uint64_t index_h, t_dynarray *darr)
{
	if (index_l <= darr->nb_cells / 2 && index_h <= darr->nb_cells / 2)
	{
		if (index_l < index_h)
			return (index_l);
		return (index_h);
	}
	if (index_l >= darr->nb_cells / 2 && index_h >= darr->nb_cells / 2)
	{
		if (darr->nb_cells - index_l > darr->nb_cells - index_h)
			return (index_h);
		return (index_l);
	}
	if (index_l <= darr->nb_cells / 2 && index_h >= darr->nb_cells / 2)
	{
		if (index_l < darr->nb_cells - index_h)
			return (index_l);
		return (index_h);
	}
	if (index_l >= darr->nb_cells / 2 && index_h <= darr->nb_cells / 2)
	{
		if (darr->nb_cells - index_l < index_h)
			return (index_l);
		return (index_h);
	}
	return (0);
}

int	ft_insert_sort2(t_dynarray *darr, t_dynarray *darr2, int l, int h)
{
	int	x;
	int	*tab2;

	x = 0;
	tab2 = (int *)darr2->list;
	if (tab2[0] == l)
	{
		ft_ps(darr2, darr, 1, 1);
		ft_rs(darr, 1, 1);
		l++;
	}
	else if (tab2[0] == h)
	{
		ft_ps(darr2, darr, 1, 1);
		x++;
		h--;
	}
	else if (ft_find_next(ft_lowest_index(darr2),
			ft_highest_index(darr2), darr2) > darr2->nb_cells / 2)
		ft_rrs(darr2, 1, 0);
	else
		ft_rs(darr2, 1, 0);
	return (x);
}

int	ft_insert_sort(t_dynarray *darr, t_dynarray *darr2)
{
	int	 *tab2;
	int	 l;
	int	 h;
	int	 x;

	x = 0;
	while (darr2->nb_cells > 0)
	{
		tab2 = (int *)darr2->list;
		l = tab2[ft_lowest_index(darr2)];
		h = tab2[ft_highest_index(darr2)];
		x += ft_insert_sort2(darr, darr2, l, h);
	}
	ft_rs(darr, x, 1);
	return (1);
}

int	ft_count_sorted(t_dynarray *darr, bool cmprt)
{
	uint64_t	i;
	int			*tab;

	tab = (int *)darr->list;
	if (!cmprt || !(((uint64_t)tab[darr->nb_cells - 1] == darr->nb_cells - 1)))
		return (0);
	i = darr->nb_cells - 1;
	if (cmprt)
		while (i > 0 && tab[i] == tab[i - 1] + 1)
			i--;
	else
		while (i > 0 && tab[i] == tab[i - 1] - 1)
			i--;
	return (darr->nb_cells - 1 - i);
}
