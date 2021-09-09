#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *nstr)
{
	unsigned long long int	nbr;
	int						sign;

	sign = 1;
	nbr = 0;
	if (*nstr >= '0' && *nstr <= '9')
	{
		while (*nstr)
		{
			if (!(*nstr >= '0' && *nstr <= '9'))
				return (0);
			nbr = nbr * 10 + (*nstr - 48);
			nstr++;
			if (nbr > 2147483647)
				return (0);
		}
	}
	else
		return (0);
	return (nbr);
}

int *ft_create_fill_tab(int size, char **argv)
{
	int			*tab;
	int	i;

	i = 0;
	if(!(tab = malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (tab);
}

int main(int argc, char **argv)
{
	int			i;
	int			*tab;

	i = 1;
	if (argc == 1 || !argv)
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
	tab = ft_create_fill_tab(argc - 1, argv);
	i = 0;
	while (i < argc - 1)
	{
		printf("%i ", tab[i]);
		i++;
	}
	return (0);
}







//pb pa
tab1[pos] = tab2[pos];
write(1, "pa\n", 1);
tab2[pos] = tab1[pos];
write(1, "pb\n", 1);





//sa sb
if (tab[pos] > tab[pos + 1])
{
	ft_swap(&tab[0], &tab[1])
		write(1, "sa\n", 3);
}

//ra rb rra rrb
if (pos - new_pos < 0)
{
	if (abs(pos - new_pos) > (argc - 1) / 2)
		rotate = argc - 1 - (pos - new_pos);
	else
		rotate = new_pos - pos;
}
else
{
	if (abs(pos - new_pos) > (argc - 1) / 2)
		rotate = argc - 1 - (new_pos - pos);
	else
		rotate = pos - new_pos;
}





