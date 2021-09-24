#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

int		ft_ps_atoi(const char *nstr)
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
		tab[i] = ft_ps_atoi(argv[i + 1]);
		i++;
	}
	darr->nb_cells = argc - 1;
	return (0);
}

void ft_print_stack(t_dynarray *darr, bool cmprt)
{
	int *tab;
	uint64_t i;

	i = 0;
	tab = darr->list;
	if (cmprt)
		printf("stack A = ");
	else
		printf("stack B = ");
	while (i < darr->nb_cells)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
