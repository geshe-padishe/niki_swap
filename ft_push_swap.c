#include "ft_push_swap.h"

//int ft_is_sorted(t_dynarray *darr, t_dynarray *darr2)
//{
//	uint64_t i;
//
//	i = 1;
//	while (i < darr->nb_cells)
//	{
//		if (*(int *)dynacc(darr, i - 1) )
//		i++;
//	}
//	return (1);
//}

int ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, bool cmprt)
{	
	int middle;
	uint64_t i;
	char stack;

	stack = 'A';
	if (!cmprt)
		stack = 'B'; ft_print_stack(darr2, stack);
	i = 0;
	printf("----------------------------------------\n                    %c\n", stack);
	printf("nb_cells = %llu | ", darr->nb_cells);
	printf("nb_cells2 = %llu | ", darr2->nb_cells);
	middle = ft_find_middle(darr);
	printf("middle = %d\n", middle);
	stack = 'A';
	if (!cmprt)
		stack = 'B'; ft_print_stack(darr2, stack);
	ft_print_stack(darr, stack);
	if (darr->nb_cells == 2)
	{
		if (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr, 1))
			ft_sw(darr);
		ft_ps(darr, darr2, 2);
	}
	else if (darr->nb_cells == 3)
	{
		ft_fast_sort(darr, darr2); 
		ft_ps(darr, darr2, 3);
	}
	else
	{
		while (i < darr->nb_cells)
		{
			if (cmprt)
			{
				if (*(int *)dynacc(darr, 0) < middle)
					ft_ps(darr, darr2, 1);
				else
					ft_rs(darr, 1);
			}
			else
			{
				if (*(int *)dynacc(darr, 0) > middle)
					ft_ps(darr, darr2, 1);
				else
					ft_rs(darr, 1);
			}
			i++;
		}
		printf("----------------------------------------\n");
		ft_sort_stack(darr, darr2, cmprt);
		ft_sort_stack(darr2, darr, !cmprt);
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
	ft_sort_stack(&darr, &darr2, 1);
}
