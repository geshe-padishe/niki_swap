#include "ft_push_swap.h"

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
			ft_rrs(darr);
		else
		{
			ft_rrs(darr);
			ft_sw(darr);
		}
	}
	else
		return (ft_dfast_sort2(darr, darr2));
	return (0);
}

