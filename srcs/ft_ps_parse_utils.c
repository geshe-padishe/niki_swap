/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:35:22 by ngenadie          #+#    #+#             */
/*   Updated: 2021/11/01 15:31:49 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_ps_index(t_dynarray *darr)
{
	int			*tab;
	void		*tmp;
	uint64_t	i;

	i = 0;
	tab = (int *)darr->tmp;
	while (i < darr->nb_cells)
	{
		tab[i] = ft_count_lower(darr, i, 0);
		i++;
	}
	tmp = darr->list;
	darr->list = darr->tmp;
	darr->tmp = tmp;
	return (1);
}
