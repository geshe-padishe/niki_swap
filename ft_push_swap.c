#include "ft_push_swap.h"

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

int ft_scan(t_dynarray *darr, int old_middle, int middle)
{
	int i;
	int *tab;

	i = 0;
	tab = (int *)darr->list;
	while (i < darr->nb_cells)
	{
		if (tab[i] >= old_middle && tab[i] < middle)
			return (1);
		i++;
	}
	return (0);
}

int ft_move_lower(t_dynarray *darr, t_dynarray *darr2, int old_middle, int middle)
{
	uint64_t i;
	int *tab;
	int count;

	count = 0;
	i = 0;
	while (ft_scan(darr, old_middle, middle))
	{
		tab = (int *)darr->list;
//		printf("old_m = %d, middle = %d\n", old_middle, middle);
//		printf("tab[0]: %d\n", tab[0]);
		if (tab[0] >= old_middle && tab[0] < middle)
			ft_ps(darr, darr2, 1, 0);
		else
		{
			ft_rs(darr, 1, 1);
			count++;
		}
		i++;
	}
	ft_rrs(darr, count, 1);
	return (0);
}

int ft_find_sep(t_dynarray *darr)
{
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
	if (darr->nb_cells < 26)
		ft_small_sort(darr, darr2, cmprt);
	else
		while (!ft_is_sorted(darr, darr2))
		{
			ft_print_stack(darr, cmprt);
			ft_print_stack(darr2, !cmprt);
			old_middle = middle;
			middle = count * ft_find_sep(darr);
			ft_move_lower(darr, darr2, old_middle, middle);
			ft_insert_sort(darr, darr2, cmprt);
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
		if (ft_count_nb(argv[1]) < 1)
		{
			write(1, "Error\n", 6);
			return (-1);	
		}
		if (ft_parse_string(argc, argv, &darr) == -1)
		{
			write(1, "Error\n", 6);
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
			write(1, "Error\n", 6);
			return (-1);
		}
	}
	ft_ps_index(&darr);
	if (ft_index_check(darr) == 0)
	{
		printf("Error\n");
		return (-1);
	}
	ft_sort_stack(&darr, &darr2, 1, argc, &max_sorts);
//	ft_print_stack(&darr, 1);
//	ft_print_stack(&darr2, 0);
	if (ft_is_sorted(&darr, &darr2) == 0)
		printf("STACK NOT SORTED!!\n");
	return (0);
}
