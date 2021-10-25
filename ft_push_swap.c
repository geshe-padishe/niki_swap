#include "ft_push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	ft_index_check(t_dynarray darr)
{
	int	i;
	int	j;
	int	*tab;

	j = 0;
	i = 0;
	tab = (int *)darr.list;
	while (i < darr.nb_cells)
	{
		j = 0;
		while (j < darr.nb_cells)
		{
			if (tab[i] == tab[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_is_sorted(t_dynarray *darr, t_dynarray *darr2)
{
	uint64_t	i;

	i = 0;
	while (i < darr->nb_cells)
	{
		if (*(int *)dynacc(darr, i) != i)
			return (0);
		i++;
	}
	return (1);
}

int	ft_scan(t_dynarray *darr, int old_mid, int mid)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)darr->list;
	while (i < darr->nb_cells)
	{
		if (tab[i] >= old_mid && tab[i] < mid)
			return (1);
		i++;
	}
	return (0);
}

int	ft_move_lower(t_dynarray *darr, t_dynarray *darr2, int old_mid, int mid)
{
	uint64_t	i;
	int			*tab;
	int			count;
	static bool	call_nb = 0;

	count = 0;
	i = 0;
	while (ft_scan(darr, old_mid, mid))
	{
		tab = (int *)darr->list;
		if (tab[0] >= old_mid && tab[0] < mid)
			ft_ps(darr, darr2, 1, 0);
		else
		{
			ft_rs(darr, 1, 1);
			count++;
		}
		i++;
	}
	if (darr->nb_cells > 3 && call_nb != 0)
		ft_rrs(darr, count, 1);
	call_nb = 1;
	return (0);
}

int	ft_find_sep(t_dynarray *darr)
{
	if (darr->nb_cells < 1)
		return (0);
	if (darr->nb_cells > 60 && darr->nb_cells < 150)
		return (darr->nb_cells / 3.2);
	else if (darr->nb_cells > 150)
		return (darr->nb_cells / (darr->nb_cells / 80));
	else
		return (darr->nb_cells / 2);
}

int	ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{
	int		mid;
	int		old_mid;
	int		partition;
	bool	mid_info;

	partition = ft_find_sep(darr);
	mid_info = 0;
	mid = partition;
	old_mid = 0;
	if (darr->nb_cells < 26)
		ft_small_sort(darr, darr2, cmprt);
	else
		while (!ft_is_sorted(darr, darr2))
		{
			if (mid_info != 0)
			{
				old_mid = mid;
				mid += partition;
			}
			ft_move_lower(darr, darr2, old_mid, mid);
			ft_insert_sort(darr, darr2, cmprt);
			mid_info = 1;
		}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dynarray	darr;
	t_dynarray	darr2;

	if (argc == 2)
	{
		if ((init_dynarray(&darr, ft_count_nb(argv[1]), 4)) == -1)
			return (-1);
		if ((init_dynarray(&darr2, ft_count_nb(argv[1]), 4)) == -1)
			return (-1);
		if (ft_count_nb(argv[1]) < 1)
			return (ft_error());
		if (ft_parse_string(argc, argv, &darr) == -1)
			return (ft_error());
	}
	else if (argc > 2)
	{
		if ((init_dynarray(&darr, argc - 1, 4)) == -1)
			return (-1);
		if ((init_dynarray(&darr2, argc - 1, 4)) == -1)
			return (-1);
		if (ft_parse(argc, argv, &darr) == -1)
			return (-1);
	}
	else
		return (ft_error());
	ft_ps_index(&darr);
	if (ft_index_check(darr) == 0)
		return (ft_error());
	ft_sort_stack(&darr, &darr2, 1);
//	if (ft_is_sorted(&darr, &darr2) == 0)
//		printf("STACK NOT SORTED!!\n");
	return (0);
}
