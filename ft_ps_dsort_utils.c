#include "ft_push_swap.h"

uint64_t ft_find_next(uint64_t index_l, uint64_t index_h, t_dynarray *darr)
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

uint64_t ft_lowest_index(t_dynarray *darr)
{
	uint64_t i;
	int *tab;
	uint64_t index;
	int nb;

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

uint64_t ft_highest_index(t_dynarray *darr)
{
	uint64_t i;
	int *tab;
	uint64_t index;
	int nb;

	i = 0;
	index = 0;
	tab = darr->list;
	nb = tab[0];
	while (i < darr->nb_cells)
	{
		if (tab[i] > nb)
		{
			nb = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int ft_insert_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int *tab2;
	int l;
	int h;
	int x;

	x = 0;
	printf("              INSERT SORT              \n");
	ft_print_stack(darr, cmprt);
	ft_print_stack(darr2, !cmprt);
	while (darr2->nb_cells > 0)
	{
//		printf("ft_find_next: %llu\n", ft_find_next(ft_lowest_index(darr2), ft_highest_index(darr2), darr2));
//		printf("l = %d, h = %d\nl_ix: %llu, h_ix: %llu\n", l, h, ft_lowest_index(darr2), ft_highest_index(darr2));
		tab2 = (int *)darr2->list;
		l = tab2[ft_lowest_index(darr2)];
		h = tab2[ft_highest_index(darr2)];
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
		else if (ft_find_next(ft_lowest_index(darr2), ft_highest_index(darr2), darr2) > darr2->nb_cells / 2)
			ft_rrs(darr2, 1, 0);
		else
			ft_rs(darr2, 1, 0);
	}
		ft_rs(darr, x, 1);
	return (1);
}

int ft_count_sorted(t_dynarray *darr, bool cmprt)
{
	uint64_t i;
	int *tab;

	tab = (int *)darr->list;
	if (!cmprt || !(((uint64_t)tab[darr->nb_cells - 1] == darr->nb_cells - 1)))
		return (0);
	i = darr->nb_cells - 1;
	if (cmprt)
		while (i > 0 && tab[i] == tab[i - 1] + 1)
			i--;
	else
		while (i > 0  &&tab[i] == tab[i - 1] - 1)
			i--;
	return (darr->nb_cells - 1 - i);
}

int ft_dfast_sort3(t_dynarray *darr, bool cmprt)
{
	int *tab;

	tab = (int *)darr->list;
	if (tab[0] < tab[1] && tab[0] < tab[2])
	{
		if (tab[1] < tab[2])
		{
			ft_rs(darr, 1, cmprt);
			ft_sw(darr, cmprt);
		}
		else
			ft_rs(darr, 1, cmprt);
	}
	return (0);
}

int ft_dfast_sort2(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int *tab;

	tab = (int *)darr->list;
	if (tab[2] < tab[0] && tab[2] < tab[1])
	{
		if (tab[0] < tab[1])
			ft_sw(darr, cmprt);
	}
	else
		return (ft_dfast_sort3(darr, cmprt));
	return (0);
}

int ft_dfast_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int *tab;

	tab = (int *)darr->list;
	if (tab[1] < tab[0] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])
			ft_rrs(darr, 1, cmprt);
		else
		{
			ft_rrs(darr, 1, cmprt);
			ft_sw(darr, cmprt);
		}
	}
	else
		return (ft_dfast_sort2(darr, darr2, cmprt));
	return (0);
}
