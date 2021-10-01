#include "ft_push_swap.h"

uint64_t ft_find_next(int nb, t_dynarray *darr)
{
	uint64_t i;
	uint64_t j;
	int *tab;

	i = 0;
	j = 0;
	tab = (int *)darr->list;
	while (i < darr->nb_cells)
	{
		if (nb == tab[i] + 1)
			return (i);
		i++;
	}	
	while (j < darr->nb_cells)
	{
		if (nb == tab[j] - 1)
			return (i);
		i++;
	}	
	return (0);
}

int ft_insert_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int *tab;
	int *tab2;
	int j;

	tab = (int *)darr->list;
	tab2 = (int *)darr2->list;
	while (darr2->nb_cells > 0)
	{

		j = 0;
		if (*(int *)dynacc(darr, 0) == *(int *)dynacc(darr2, 0) + 1)
			ft_ps(darr2, darr, 1, cmprt);
		else
			while (*(int *)dynacc(darr, 0) != *(int *)dynacc(darr2, 0) + 1)
			{
				//printf("darr 0 = %d, darr2 0 = %d\n", *(int *)dynacc(darr, 0), *(int *)dynacc(darr2, 0));
				//ft_print_stack(darr, cmprt);
				//ft_print_stack(darr2, !cmprt);
				j++;
				if (ft_find_next(tab[0], darr2) > (darr->nb_cells + 1) / 2)
					ft_rrs(darr2, 1, cmprt);
				else
					ft_rs(darr2, 1, cmprt);
			}
		//ft_rrs(darr, j);
	}
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

