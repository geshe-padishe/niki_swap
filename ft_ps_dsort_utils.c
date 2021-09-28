#include "ft_push_swap.h"

int ft_insert_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int *tab;
	int *tab2;
	int j;

	tab = (int *)darr->list;
	tab2 = (int *)darr2->list;
	if (cmprt)
	{
		while (darr2->nb_cells > 0)
		{
			ft_print_stack(darr, cmprt);
			ft_print_stack(darr2, !cmprt);
			printf("prutete");
			j = 0;
			if (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr2, 0))
				ft_ps(darr2, darr, 1);
			else
				while (*(int *)dynacc(darr, 0) < *(int *)dynacc(darr2, 0))
				{
					j++;
					ft_rs(darr2, 1);
					ft_insert_sort(darr, darr2, cmprt);
				}
			ft_rrs(darr2, j);
		}
	}
	else
		while (darr->nb_cells > 0)
		{
			ft_print_stack(darr, cmprt);
			ft_print_stack(darr2, !cmprt);
			printf("prutete");
			j = 0;
			if (*(int *)dynacc(darr, 0) < *(int *)dynacc(darr2, 0))
				ft_ps(darr2, darr, 1);
			else
				while (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr2, 0))
				{
					j++;
					ft_rs(darr, 1);
				}
			ft_rrs(darr, j);
		}
	return (1);
}

int ft_count_sorted(t_dynarray *darr, bool cmprt)
{
	uint64_t i;
	int *tab;

	tab = (int *)darr->list;
	i = darr->nb_cells - 1;
	if (cmprt)
		while (tab[i] == tab[i - 1] + 1 && i > 0)
			i--;
	else
		while (tab[i] == tab[i - 1] - 1 && i > 0)
			i--;
	return (darr->nb_cells - 1 - i);
}

int ft_dfast_sort3(t_dynarray *darr)
{
	int *tab;

	printf("fast sort 3");
	tab = (int *)darr->list;
	if (tab[0] < tab[1] && tab[0] < tab[2])
	{
		if (tab[1] < tab[2])
		{
			ft_rs(darr, 1);
			ft_sw(darr);
		}
		else
			ft_rs(darr, 1);
	}
	return (0);
}

int ft_dfast_sort2(t_dynarray *darr, t_dynarray *darr2)
{
	int *tab;

	//printf("fast sort 2");
	tab = (int *)darr->list;
	if (tab[2] < tab[0] && tab[2] < tab[1])
	{
		if (tab[0] < tab[1])
			ft_sw(darr);
	}
	else
		return (ft_dfast_sort3(darr));
	return (0);
}

int ft_dfast_sort(t_dynarray *darr, t_dynarray *darr2)
{
	int *tab;

	//printf("fast sort");
	tab = (int *)darr->list;
	if (tab[1] < tab[0] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])
			ft_rrs(darr, 1);
		else
		{
			ft_rrs(darr, 1);
			ft_sw(darr);
		}
	}
	else
		return (ft_dfast_sort2(darr, darr2));
	return (0);
}

