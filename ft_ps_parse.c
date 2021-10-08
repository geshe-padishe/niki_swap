#include "ft_push_swap.h"

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
		nstr++;
		if (*(nstr - 1) == '-')
			sign = -1;
	}
	if (*nstr >= '0' && *nstr <= '9')
	{
		while (*nstr >= '0' && *nstr <= '9')
		{
			nbr = nbr * 10 + (*nstr - 48);
			nstr++;
			if ((nbr > 2147483647 && sign == -1) || (nbr > 2147483648))
				return (0);
		}
	}
	else
		return (0);
	return ((int)nbr * sign);
}

int ft_parse(int argc, char **argv, t_dynarray *darr)
{
	int			i;
	int			*tab;

	i = 1;
	if (argc < 3 || !argv)
	{
		write(1, "<3<3<3Error\n", 10);
		return (-1);
	}
	while (i < argc)
	{
		if (ft_ps_atoi(argv[i]) == 0 && argv[i][0] != '0')
		{
			write(1, "<<<<Error\n", 8);
			return (-1);
		}
		i++;
	}
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

int ft_parse_string(int argc, char **argv, t_dynarray *darr)
{
	int i;
	int j;
	int *tab;

	tab = (int *)darr->list;
	i = 0;
	j = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' && i != 0)
			i++;
		if ((argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] == '-')
		{
			tab[j] = ft_ps_atoi(&argv[1][i]);
			ft_print_stack(darr, 1);
			j++;
			if (argv[1][i] == '-')
				i++;
			if (argv[1][i] < '0' || argv[1][i] > '9')
				return (-1);
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
				i++;
		}
		else
			return (-1);
	}
	darr->nb_cells = j;
	return (0);
}

int ft_count_nb(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			count++;
		}
		else
			i++;
	}	
	return (count);
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
