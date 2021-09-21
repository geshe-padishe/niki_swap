#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

int		ft_atoi(const char *nstr)
{
	long long int	nbr;
	int						sign;

	sign = 1;
	nbr = 0;
	if (*nstr == '-' || *nstr == '+')
	{
		if (*nstr == '-')
			sign = -1;
		nstr++;
	}
	if (*nstr >= '0' && *nstr <= '9')
	{
		while (*nstr)
		{
			if (!(*nstr >= '0' && *nstr <= '9'))
				return (0);
			nbr = nbr * 10 + (*nstr - 48);
			nstr++;
			if (nbr > 2147483647 || nbr < -2147483648)
				return (0);
		}
	}
	else
		return (0);
	return (nbr * sign);
}

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

int ft_ps(t_dynarray *darr, t_dynarray *darr2)
{
	int tmp;

	tmp = *(int *)dynacc(darr, 0);
	pop_dynarray(darr, 1, 1);
	push_dynarray(darr2, &tmp, 1, 1);
	write(1, "ps\n", 3);
	return (0);
}

int ft_rs(t_dynarray *darr)
{
	int tmp;
	int *tab;

	tab = (int *)darr->list;
	tmp = *tab;
	pop_dynarray(darr, 1, 1);
	push_dynarray(darr, &tmp, 1, 0);
	write(1, "rs\n", 3);
	return (0);
}

int ft_rrs(t_dynarray *darr)
{
	int tmp;
	int *tab;

	tab = (int *)darr->list;
	tmp = tab[darr->nb_cells - 1];
	pop_dynarray(darr, 1, 0);
	push_dynarray(darr, &tmp, 1, 1);
	write(1, "rrs\n", 3);
	return (0);
}

int ft_parse(int argc, char **argv, t_dynarray *darr)
{
	int			i;
	int			*tab;

	i = 1;
	if (argc < 3 || !argv)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	while (i < argc)
	{
		if (!ft_atoi(argv[i]))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	if ((init_dynarray(darr, argc - 1, 4)) == -1)
		return (-1);
	tab = (int *)darr->list;
	i = 0;
	while (i < argc - 1)
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	darr->nb_cells = argc - 1;
	return (0);
}

void ft_print_stack(t_dynarray *darr, char stack)
{
	int *tab;
	uint64_t i;

	i = 0;
	tab = darr->list;
	printf("stack %c = ", stack);
	while (i < darr->nb_cells)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

uint64_t ft_count_lower(t_dynarray *darr, uint64_t index)
{
	uint64_t i;
	uint64_t count;
	int *stack;

	stack = (int *)darr->list;
	count = 0;
	i = 0;
	while (i < darr->nb_cells)
	{
		if (stack[i] < stack[index])
			count++;
		i++;
	}
	return (count);
}

int ft_find_middle(t_dynarray *darr)
{
	uint64_t i;

	i = 0;
	while (i < darr->nb_cells)
	{
		if (ft_count_lower(darr, i) == darr->nb_cells / 2)
			return (*(int *)dynacc(darr, i));
		i++;
	}
	return (-1);
}


int ft_fast_sort3(t_dynarray *darr, t_dynarray *darr2)
{
	int *tab;

	tab = (int *)darr->list;
	if (tab[0] < tab[2])
	{
		if (tab[1] > tab[2])
		{
			ft_ps(darr, darr2);
			ft_ps(darr, darr2);
			ft_rs(darr);
			ft_ps(darr2, darr);
			ft_ps(darr2, darr);
			ft_rrs(darr);
		}
		else
			ft_sw(darr);
	}
	return (0);
}

int ft_fast_sort2(t_dynarray *darr, t_dynarray *darr2)
{
	int *tab;

	tab = (int *)darr->list;
	if (tab[0] < tab[1])
	{
		if (tab[1] > tab[2])
		{
			ft_ps(darr, darr2);
			ft_sw(darr);
			ft_ps(darr2, darr);
		}	
		else
			return (0);
	}
	else
		ft_fast_sort3(darr, darr2);
	return (0);
}

int ft_fast_sort(t_dynarray *darr, t_dynarray *darr2)
{
	int *tab;

	tab = (int *)darr->list;
	if (tab[0] > tab[1])
	{
		if (tab[1] > tab[2])
		{
			ft_sw(darr);
			ft_ps(darr, darr2);
			ft_ps(darr, darr2);
			ft_rs(darr);
			ft_ps(darr2, darr);
			ft_ps(darr2, darr);
			ft_rrs(darr);
		}
		else
		{
			ft_sw(darr);
			ft_ps(darr, darr2);
			ft_sw(darr);
			ft_ps(darr2, darr);
		}
	}
	else
		return (ft_fast_sort2(darr, darr2));
	return (0);
}

int ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, char stack, bool cmprt)
{	
	int middle;
	uint64_t i;

	i = 0;
	printf("----------------------------------------\n                             %c\n", stack);
	printf("nb_cells = %llu\n", darr->nb_cells);
	printf("nb_cells2 = %llu\n", darr2->nb_cells);
	middle = ft_find_middle(darr);
	printf("middle = %d\n", middle);
	ft_print_stack(darr, stack);
	ft_print_stack(darr2, '2');
	if (darr->nb_cells == 2)
	{
		if (*(int *)dynacc(darr, 0) > *(int *)dynacc(darr, 1))
			ft_sw(darr);
	}
	else if (darr->nb_cells == 3)
		ft_fast_sort(darr, darr2); 
	else
	{
		while (i < darr->nb_cells)
		{
			if (cmprt
			if (*(int *)dynacc(darr, 0) < middle)
				ft_ps(darr, darr2);
			else
				ft_rs(darr);
			i++;
		}
		printf("----------------------------------------------------\n");
		ft_sort_stack(darr2, darr, '2', !cmprt);
		ft_sort_stack(darr, darr2, stack, cmprt);
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
	ft_sort_stack(&darr, &darr2, 'A', 1);
}
