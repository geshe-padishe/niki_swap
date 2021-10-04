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

int ft_index_check(t_dynarray darr)
{
	int i;
	int j;
	int *tab;

	j = 0;
	i = 0;
	tab = (int *)darr.list;
	while (i < darr.nb_cells)
	{
		j = i + 1;
		while (j < darr.nb_cells)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
				ft_sw(darr, cmprt);
		if (!cmprt)
			if (*(int *)dynacc(darr, 0) < *(int *)dynacc(darr, 1))
				ft_sw(darr, cmprt);
		return (1);
	}
	else if (darr->nb_cells == 3)
	{
		if (cmprt)
			ft_fast_sort(darr, darr2, cmprt); 
		else
			ft_dfast_sort(darr, darr2, cmprt);
		return (1);
	}
	return (0);
}

int ft_move_lower(t_dynarray *darr, t_dynarray *darr2, int old_middle, int middle)
{
	uint64_t i;
	int *tab;

	i = 0;
	while (i < darr->nb_cells)
	{
		tab = darr->list;
		if (tab[0] >= old_middle && tab[0] < middle)
			ft_ps(darr, darr2, 1, 1);
		else
			ft_rs(darr, 1, 1);
		i++;
	}
	return (0);
}

int ft_find_sep(t_dynarray *darr)
{
	darr->nb_cells = darr->nb_cells;
	if (darr->nb_cells > 150)
		return (darr->nb_cells / (darr->nb_cells / 100));
	else
		return (darr->nb_cells / 2);
}

int ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, bool cmprt, int argc, int *max_sorts)
{
	int middle;
	int old_middle;
	int count;
//	ft_print_stack(darr, cmprt);
//	ft_print_stack(darr2, !cmprt);
	middle = 0;
	count = 1;
	while (!ft_is_sorted(darr, darr2))
	{
		ft_print_stack(darr, cmprt);
		ft_print_stack(darr2, !cmprt);
		old_middle = middle;
		middle = count * ft_find_sep(darr);
		printf("old_m = %d, middle = %d\n", old_middle, middle);
		ft_move_lower(darr, darr2, old_middle, middle);
		//ft_insert_sort(darr, darr2, cmprt);
		count++;
	}
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
	

	if (argc == 2)
	{
		if ((init_dynarray(&darr, ft_count_nb(argv[1]), 4)) == -1)
			return (-1);
		if ((init_dynarray(&darr2, ft_count_nb(argv[1]), 4)) == -1)
			return (-1);
		if (ft_parse_string(argc, argv, &darr) == -1)
		{
			write(1, "2222Error\n", 10);
			return (-1);
		}
	}
	else if (argc > 2)
	{
		if ((init_dynarray(&darr, argc - 1, 4)) == -1)
			return (-1);
		if ((init_dynarray(&darr2, argc - 1, 4)) == -1)
			return (-1);
		if (ft_parse(argc, argv, &darr) == -1)
		{
			write(1, ">>>222Error\n", 10);
			return (-1);
		}
	}
	ft_ps_index(&darr);
	if (ft_index_check(darr) == 0)
	{
		printf("1111 Error\n");
		return (-1);
	}
	ft_sort_stack(&darr, &darr2, 1, argc, &max_sorts);
	ft_print_stack(&darr, 1);
	ft_print_stack(&darr2, 0);
	if (ft_is_sorted(&darr, &darr2) == 0)
		printf("STACK NOT SORTED!!\n");
	return (0);
}
