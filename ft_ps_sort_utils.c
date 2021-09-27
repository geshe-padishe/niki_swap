#include "ft_push_swap.h"

uint64_t ft_count_lower(t_dynarray *darr, uint64_t index, int nb_sorted)
{
	uint64_t i;
	uint64_t count;
	int *stack;

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

uint64_t ft_count_bigger(t_dynarray *darr, uint64_t index, int nb_sorted)
{
	uint64_t i;
	uint64_t count;
	int *stack;

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

int ft_find_middle(t_dynarray *darr, int nb_sorted, bool cmprt)
{
	uint64_t i;

	i = 0;
	while (i < darr->nb_cells - nb_sorted)
	{
		if (cmprt)
			if ((ft_count_lower(darr, i, nb_sorted) == (darr->nb_cells - nb_sorted - 1) / 2) &&
				(ft_count_bigger(darr, i, nb_sorted) == (darr->nb_cells - nb_sorted) / 2))
				return (*(int *)dynacc(darr, i));
		if (!cmprt)
			if ((ft_count_lower(darr, i, nb_sorted) == (darr->nb_cells - nb_sorted) / 2) &&
				(ft_count_bigger(darr, i, nb_sorted) == (darr->nb_cells - nb_sorted - 1) / 2))
				return (*(int *)dynacc(darr, i));
		i++;
	}
	return (-1);
}

int ft_fast_sort3(t_dynarray *darr)
{
	int *tab;

	//printf("fast sort 3");
	tab = (int *)darr->list;
	if (tab[0] < tab[1] && tab[0] < tab[2])
	{
		if (tab[1] > tab[2])
		{
			ft_rrs(darr, 1);
			ft_sw(darr);
		}
	}
	return (0);
}

int ft_fast_sort2(t_dynarray *darr, t_dynarray *darr2)
{
	int *tab;

	//printf("fast sort 2");
	tab = (int *)darr->list;
	if (tab[2] < tab[0] && tab[2] < tab[1])
	{
		if (tab[0] < tab[1])
		{
			ft_sw(darr);
			ft_rrs(darr, 1);
		}
		else
		{
			ft_sw(darr);
			ft_rrs(darr, 1);
		}
	}
	else
		return (ft_fast_sort3(darr));
	return (0);
}

int ft_fast_sort(t_dynarray *darr, t_dynarray *darr2)
{
	int *tab;

	//printf("fast sort");
	tab = (int *)darr->list;
	if (tab[1] < tab[0] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])
			ft_sw(darr);
		else
			ft_rs(darr, 1);
	}
	else
		return (ft_fast_sort2(darr, darr2));
	return (0);
}
