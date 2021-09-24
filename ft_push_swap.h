#include "dynarray.h"

uint64_t ft_count_lower(t_dynarray *darr, uint64_t index);
int ft_find_middle(t_dynarray *darr);
int ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, bool cmprt, int argc);
int		ft_ps_atoi(const char *nstr);
int ft_parse(int argc, char **argv, t_dynarray *darr);
void ft_print_stack(t_dynarray *darr, char stack);
int ft_sw(t_dynarray *darr);
int ft_ps(t_dynarray *darr, t_dynarray *darr2, uint64_t n);
int ft_rs(t_dynarray *darr, uint64_t n);
int ft_rrs(t_dynarray *darr);
int ft_dfast_sort3(t_dynarray *darr);
int ft_dfast_sort2(t_dynarray *darr, t_dynarray *darr2);
int ft_dfast_sort(t_dynarray *darr, t_dynarray *darr2);
int ft_fast_sort3(t_dynarray *darr);
int ft_fast_sort2(t_dynarray *darr, t_dynarray *darr2);
int ft_fast_sort(t_dynarray *darr, t_dynarray *darr2);
