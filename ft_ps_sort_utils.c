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

void ft_insrt_two(t_dynarray *darr, t_dynarray *darr2)
{
	if (*(int *)dynacc(darr2, 0) < *(int *)dynacc(darr2, 1))
		ft_sw(darr2, 0);
	ft_ps(darr2, darr, 2, 1);
}

void ft_five_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	ft_move_lower(darr, darr2, 0, 2);
	ft_fast_sort(darr, darr2, 1);
	ft_insrt_two(darr, darr2);
}

int ft_small_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	if (ft_is_sorted(darr, darr2))
		return (1);
	if (darr->nb_cells > 3)
		ft_five_sort(darr, darr2, 1);
	if (darr->nb_cells == 2)
	{
		if (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr, 1))
			ft_sw(darr, cmprt);
	}
	else if (darr->nb_cells == 3)
	{
		if (cmprt)
			ft_fast_sort(darr, darr2, cmprt); 
		else
			ft_dfast_sort(darr, darr2, cmprt);
	}
	if (darr2->nb_cells > 0)
		ft_insert_sort(darr, darr2, cmprt);
	return (1);
}

int ft_fast_sort3(t_dynarray *darr, bool cmprt)
{
	int *tab;

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

int ft_fast_sort2(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int *tab;

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

int ft_fast_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int *tab;

	tab = (int *)darr->list;
	if (tab[1] < tab[0] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])
			ft_sw(darr, cmprt);
		else
			ft_rs(darr, 1, cmprt);
	}
	else
		return (ft_fast_sort2(darr, darr2, cmprt));
	return (0);
}
