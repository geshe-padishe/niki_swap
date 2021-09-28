#include "ft_push_swap.h"

//uint64_t ft_nb_sorted(t_dynarray *darr, bool cmprt)
//{
//	uint64_t i;
//	uint64_t nb_sorted;
//
//	nb_sorted = 0;
//	i = darr->nb_cells - 1;
//	while (i > 1)
//	{
//		if (cmprt)
//			if (*(int *)dynacc(darr, i) > *(int *)dynacc(darr, i - 1))
//				nb_sorted++;
//		if (!cmprt)
//			if (*(int *)dynacc(darr, i) < *(int *)dynacc(darr, i - 1))
//				nb_sorted++;
//		i--;
//	}
//	return (nb_sorted);
//}

int ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int ft_is_sorted(t_dynarray *darr, t_dynarray *darr2)
{
	uint64_t i;

	i = 1;
	while (i < darr->nb_cells)
	{
		if (*(int *)dynacc(darr, i - 1) > *(int *)dynacc(darr, i))
			return (0);
		i++;
	}
	i = 1;
	while (i < darr2->nb_cells)
	{
		if (*(int *)dynacc(darr2, i - 1) < *(int *)dynacc(darr2, i))
			return (0);
		i++;
	}
	return (1);
}

int ft_small_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	if (darr->nb_cells == 2)
	{
		if (cmprt)
			if (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr, 1))
				ft_sw(darr);
		if (!cmprt)
			if (*(int *)dynacc(darr, 0) < *(int *)dynacc(darr, 1))
				ft_sw(darr);
		return (1);
	}
	else if (darr->nb_cells == 3)
	{
		if (cmprt)
			ft_fast_sort(darr, darr2); 
		else
			ft_dfast_sort(darr, darr2);
		return (1);
	}
	return (0);
}

int ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, bool cmprt, int argc, int *max_sorts)
{
	int middle;
	uint64_t i;
	int j;

//	if (*max_sorts > 20)
//		return (0);
	(*max_sorts)++;
	printf("-----------------------------------\n");
	printf("nb_cells = %llu | ", darr->nb_cells);
	printf("nb_cells2 = %llu | ", darr2->nb_cells);
	printf("cmprt = %d\n", cmprt);
	ft_print_stack(darr, cmprt);
	ft_print_stack(darr2, !cmprt);

	if (ft_small_sort(darr, darr2, cmprt))
		return (0);
	else if (ft_is_sorted(darr, darr2))
	{
		ft_insert_sort(darr, darr2, cmprt);
		return (0);
	}
	else if (cmprt && (ft_is_sorted(darr, darr2) && darr2->nb_cells == 0))
		return (0);
	else if (!cmprt && (ft_is_sorted(darr2, darr) && darr->nb_cells == 0))
		return (0);
	else
	{
		ft_print_stack(darr, cmprt);
		ft_print_stack(darr2, !cmprt);
		middle = ft_find_middle(darr, cmprt);
		printf("middle = %d\n", middle);
		i = 0;
		j = 0;
		//nb_sorted[0] = 0;
		while (i < darr->nb_cells - ft_abs(ft_count_sorted(darr, cmprt)) && darr->nb_cells > 2)
		{
			if (cmprt)
			{
				if (*(int *)dynacc(darr, 0) <= middle)
					ft_ps(darr, darr2, 1);
				else
				{
					ft_rs(darr, 1);
					j++;
					i++;
				}
			}
			else
			{
				if (*(int *)dynacc(darr, 0) >= middle)
					ft_ps(darr, darr2, 1);
				else
				{
					ft_rs(darr, 1);
					j++;
					i++;
				}
			}
		}
		ft_rrs(darr, j);
	}
	ft_sort_stack(darr, darr2, cmprt, argc, max_sorts);
	ft_sort_stack(darr2, darr, !cmprt, argc, max_sorts);
	return (0);
}

int main(int argc, char **argv)
{
	t_dynarray darr;
	t_dynarray darr2;
	int nb_sorted[2];
	int max_sorts;

	max_sorts = 0;
	nb_sorted[0] = 0;
	nb_sorted[1] = 0;

	if (ft_parse(argc, argv, &darr) == -1)
		return (-1);

	if ((init_dynarray(&darr2, argc - 1, 4)) == -1)
		return (-1);
	ft_ps_index(&darr);
	ft_sort_stack(&darr, &darr2, 1, argc, &max_sorts);
	ft_print_stack(&darr, 1);
	ft_print_stack(&darr2, 0);
}
