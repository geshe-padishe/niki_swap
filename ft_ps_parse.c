/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:58:16 by ngenadie          #+#    #+#             */
/*   Updated: 2021/10/29 00:58:17 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_ps_index(t_dynarray *darr)
{
	int			*tab;
	void		*tmp;
	uint64_t	i;

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

int	ft_atoi_sign(char **nstr)
{
	int	sign;

	sign = 1;
	if (**nstr == '-' || **nstr == '+')
	{
		(*nstr)++;
		if (*(*nstr - 1) == '-')
			sign = -1;
	}
	return (sign);
}

int	ft_ps_atoi(char *nstr)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = ft_atoi_sign(&nstr);
	if (*nstr >= '0' && *nstr <= '9')
	{
		while (*nstr >= '0' && *nstr <= '9')
		{
			nbr = nbr * 10 + (*nstr - 48);
			nstr++;
			if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648))
				return (0);
		}
		if (*nstr != ' ' && *nstr != 0)
			return (0);
	}
	else
		return (0);
	return ((int)nbr * sign);
}

int	ft_parse(int argc, char **argv, t_dynarray *darr)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] == NULL)
			return (-1);
		if (ft_parse_string(argc, argv, darr, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_parse_advance(char **argv, int i, int j)
{
	while ((argv[j][i] >= '0' && argv[j][i] <= '9'))
		i++;
	while (argv[j][i] == ' ')
		i++;
	return (i);
}

int	ft_parse_string(int argc, char **argv, t_dynarray *darr, int j)
{
	int	i;
	int	nb;

	i = 0;
	while (argv[j][i])
	{
		while (argv[j][i] == ' ')
			i++;
		if ((argv[j][i] >= '0' && argv[j][i] <= '9') || argv[j][i] == '-')
		{
			nb = ft_ps_atoi(&argv[j][i]);
			if (nb == 0 && argv[j][i] != '0')
				return (-1);
			push_dynarray(darr, &nb, 1, 0);
			if (argv[j][i] == '-')
				i++;
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (-1);
			i = ft_parse_advance(argv, i, j);
		}
		else
			return (-1);
	}
	return (0);
}

int	ft_count_nb(char *str)
{
	int	i;
	int	count;

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

void	ft_print_stack(t_dynarray *darr, int cmprt)
{
	int			*tab;
	uint64_t	i;

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
