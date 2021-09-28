#include "ft_push_swap.h"

int ft_sw(t_dynarray *darr)
{
	int tmp;
	int *tab;

	tab = (int *)darr->list;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	write(1, "sw\n", 3);
	return (0);
}

int ft_ps(t_dynarray *darr, t_dynarray *darr2, uint64_t n)
{
	int tmp;
	uint64_t i;

	i = 0;
	while (i < n)
	{
		tmp = *(int *)dynacc(darr, 0);
		pop_dynarray(darr, 1, 1);
		push_dynarray(darr2, &tmp, 1, 1);
		write(1, "ps\n", 3);
		i++;
	}
	return (0);
}

int ft_rs(t_dynarray *darr, uint64_t n)
{
	int tmp;
	int *tab;
	uint64_t i;

	i = 0;
	while (i < n)
	{
		tab = (int *)darr->list;
		tmp = *tab;
		pop_dynarray(darr, 1, 1);
		push_dynarray(darr, &tmp, 1, 0);
		write(1, "rs\n", 3);
		i++;
	}
	return (0);
}

int ft_rrs(t_dynarray *darr, uint64_t n)
{
	int tmp;
	int *tab;
	uint64_t i;

	i = 0;
	while (i < n)
	{
		tab = (int *)darr->list;
		tmp = tab[darr->nb_cells - 1];
		pop_dynarray(darr, 1, 0);
		push_dynarray(darr, &tmp, 1, 1);
		write(1, "rrs\n", 4);
		i++;
	}
	return (0);
}

