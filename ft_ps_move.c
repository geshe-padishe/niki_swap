#include "ft_push_swap.h"

int ft_dsw(t_dynarray *darr, t_dynarray *darr2)
{
	int tmp;
	int *tab;

	tab = (int *)darr->list;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	tab = (int *)darr2->list;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	write(1, "ss\n", 3);
	return (0);
}

int ft_sw(t_dynarray *darr, bool cmprt)
{
	int tmp;
	int *tab;

	tab = (int *)darr->list;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	if (cmprt)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return (0);
}

int ft_ps(t_dynarray *darr, t_dynarray *darr2, uint64_t n, bool cmprt)
{
	int tmp;
	uint64_t i;

	i = 0;
	while (i < n)
	{
		tmp = *(int *)dynacc(darr, 0);
		pop_dynarray(darr, 1, 1);
		push_dynarray(darr2, &tmp, 1, 1);
		if (cmprt)
			write(1, "pb\n", 3);
		else
			write(1, "pa\n", 3);
		i++;
	}
	return (0);
}

int ft_rs(t_dynarray *darr, uint64_t n, bool cmprt)
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
		if (cmprt)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		i++;
	}
	return (0);
}

int ft_rrs(t_dynarray *darr, uint64_t n, bool cmprt)
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
		if (cmprt)
			write(1, "rra\n", 4);
		if (!cmprt)
			write(1, "rrb\n", 4);
		i++;
	}
	return (0);
}

