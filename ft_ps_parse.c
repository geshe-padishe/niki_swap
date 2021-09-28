#include "ft_push_swap.h"

uint64_t ft_count_index(t_dynarray *darr, uint64_t index, int nb_sorted)
{
	uint64_t i;
	uint64_t count;
	int *stack;

	stack = (int *)darr->list;
	count = 0;
	i = 0;
	while (i < darr->nb_cells - nb_sorted)
	{
		if (stack[i] < stack[index])
			count++;
		i++;
	}
	return (count);
}
int		ft_ps_index(t_dynarray *darr)
{
	int *tab;
	void *tmp;
	uint64_t i;

	i = 0;
	tab = (int *)darr->tmp;
	while (i < darr->nb_cells)
	{
		tab[i] = ft_count_lower(darr, i, 0);
		i++;
	}
	tmp = darr->list;
	darr->list = darr->tmp;
	darr->tmp = tmp;
	return (1);
}

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

void ft_print_stack(t_dynarray *darr, int cmprt)
{
	int *tab;
	uint64_t i;

	i = 0;
	tab = darr->list;
	if (cmprt > 0)
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
