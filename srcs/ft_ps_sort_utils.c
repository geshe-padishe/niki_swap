/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:01:39 by ngenadie          #+#    #+#             */
/*   Updated: 2021/11/01 15:14:12 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

uint64_t	ft_count_lower(t_dynarray *darr, uint64_t index, int nb_sorted)
{
	uint64_t	i;
	uint64_t	count;
	int			*stack;

	stack = (int *)darr->list;
	count = 0;
	i = 0;
	while (i < darr->nb_cells - nb_sorted)
	{
		if (stack[i] < stack[index])
			count++;
		i++;
	}
	return (count);
}

uint64_t	ft_count_bigger(t_dynarray *darr, uint64_t index, int nb_sorted)
{
	uint64_t	i;
	uint64_t	count;
	int			*stack;

	stack = (int *)darr->list;
	count = 0;
	i = 0;
	while (i < darr->nb_cells - nb_sorted)
	{
		if (stack[i] > stack[index])
			count++;
		i++;
	}
	return (count);
}

void	ft_insrt_two(t_dynarray *darr, t_dynarray *darr2)
{
	if (darr2->nb_cells == 2)
	{
		if (*(int *)dynacc(darr2, 0) < *(int *)dynacc(darr2, 1))
			ft_sw(darr2, 0);
		ft_ps(darr2, darr, 2, 1);
	}
	else
		ft_ps(darr2, darr, 1, 1);
}

void	ft_five_sort(t_dynarray *darr, t_dynarray *darr2)
{
	if (darr->nb_cells == 4)
		ft_move_lower(darr, darr2, 0, 1);
	else
		ft_move_lower(darr, darr2, 0, 2);
	ft_fast_sort(darr, 1);
	ft_insrt_two(darr, darr2);
}

int	ft_small_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	if (ft_is_sorted(darr))
		return (1);
	if (darr->nb_cells > 3 && darr->nb_cells < 6)
		ft_five_sort(darr, darr2);
	else if (darr->nb_cells == 2)
	{
		if (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr, 1))
			ft_sw(darr, cmprt);
	}
	else if (darr->nb_cells == 3)
	{
		if (cmprt)
			ft_fast_sort(darr, cmprt);
	}
	else
	{
		ft_move_lower(darr, darr2, 3, 30);
		ft_fast_sort(darr, 1);
		ft_insert_sort(darr, darr2);
	}
	return (1);
}
