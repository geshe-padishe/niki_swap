#include "ft_push_swap.h"

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
		if (*(int *)dynacc(darr2, i - 1) > *(int *)dynacc(darr2, i))
			return (0);
		i++;
	}
	return (1);
}

int ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, bool cmprt, int argc)
{	
	int middle;
	uint64_t i;

	printf("-----------------------------------\n");
	printf("nb_cells = %llu | ", darr->nb_cells);
	printf("nb_cells2 = %llu | ", darr2->nb_cells);


	i = 0;
	middle = ft_find_middle(darr);
	printf("middle = %d\n", middle);
	ft_print_stack(darr, cmprt);
	ft_print_stack(darr2, !cmprt);
	if (darr->nb_cells == 2)
	{
		if (cmprt)
			if (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr, 1))
				ft_sw(darr);
		if (!cmprt)
			if (*(int *)dynacc(darr, 0) < *(int *)dynacc(darr, 1))
				ft_sw(darr);
		ft_ps(darr, darr2, 2);
	}
	else if (darr->nb_cells == 3)
	{
		if (cmprt)
			ft_fast_sort(darr, darr2); 
		else
			ft_dfast_sort(darr, darr2);
		ft_ps(darr, darr2, 3);
	}
	else if ((darr->nb_cells == argc - 1 || darr2->nb_cells == argc - 1) && ft_is_sorted(darr, darr2))
		return (0);	
	else
	{
		while (i < darr->nb_cells)
		{
			if (cmprt)
			{
				if (*(int *)dynacc(darr, 0) <= middle)
					ft_ps(darr, darr2, 1);
				else
					ft_rs(darr, 1);
			}
			else
			{
				if (*(int *)dynacc(darr, 0) >= middle)
					ft_ps(darr, darr2, 1);
				else
					ft_rs(darr, 1);
			}
			i++;
		}
		printf("----------------------------------------\n");
		ft_sort_stack(darr, darr2, cmprt, argc);
		ft_sort_stack(darr2, darr, !cmprt, argc);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_dynarray darr;
	t_dynarray darr2;

	if (ft_parse(argc, argv, &darr) == -1)
		return (-1);

	if ((init_dynarray(&darr2, argc -1, 4)) == -1)
		return (-1);
	ft_sort_stack(&darr, &darr2, 1, argc);
	ft_print_stack(&darr, 1);
	ft_print_stack(&darr2, 0);
}
