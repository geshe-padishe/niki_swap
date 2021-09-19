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
	return (0);
}

int ft_ps(t_dynarray *darr, t_dynarray *darr2)
{
	int tmp;
	int *tab;
	int *tab2;

	tab = (int *)darr->list;
	tab2 = (int *)darr2->list;
	tmp = tab[0];
	tab[0] = tab2[0];
	tab2[0] = tmp;
	return (0);
}

int ft_rp(t_dynarray *darr)
{
	int tmp;
	int *tab;

	tab = (int *)darr->list;
	tmp = *tab;
	pop_dynarray(darr, 1, 1);
	push_dynarray(darr, &tmp, 1, 0);
	return (0);
}

int ft_rrp(t_dynarray *darr)
{
	int tmp;
	int *tab;

	tab = (int *)darr->list;
	tmp = tab[darr->nb_cells - 1];
	pop_dynarray(darr, 1, 0);
	push_dynarray(darr, &tmp, 1, 1);
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

void ft_print_stack(t_dynarray *darr)
{
	int *tab;
	uint64_t i;

	i = 0;
	tab = darr->list;
	while (i < darr->nb_cells)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

uint64_t ft_count_lower(t_dynarray *darr, int index)
{
	uint64_t i;
	uint64_t count;
	int *stack;

	stack = (int *)darr->list;
	count = 0;
	i = 0;
	while (i < darr->nb_cells)
	{
		if (stack[i] < stack[index] && (int)i != index)
			count++;
		i++;
	}
	return (count);
}

int ft_find_middle(t_dynarray *darr)
{
	uint64_t i;
	int *stack;

	stack = (int *)darr->list;
	i = 0;
	while (i < darr->nb_cells)
	{
		if (ft_count_lower(darr, i) == darr->nb_cells / 2)
			return (stack[i]);
		i++;
	}
	return (-1);
}

int main(int argc, char **argv)
{
	uint64_t i;
	int middle;
	int *tab;
	int *tab2;

	i = 0;
	t_dynarray darr;
	t_dynarray darr2;

	if (ft_parse(argc, argv, &darr) == -1)
		return (-1);
	ft_print_stack(&darr);

	if ((init_dynarray(&darr2, argc -1, 4)) == -1)
		return (-1);

	middle = ft_find_middle(&darr);
	printf("middle = %d\n", middle);

	tab = darr.list;
	tab2 = darr2.list;
	while (i < darr.nb_cells)
	{
		if (tab[i] < middle)
		{
			
		}
	}
}
