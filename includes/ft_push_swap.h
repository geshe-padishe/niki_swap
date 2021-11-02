/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:07:41 by ngenadie          #+#    #+#             */
/*   Updated: 2021/11/02 20:14:26 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include	"dynarray.h"

int			ft_ps_sign_advance(char **argv, int i, int j);
uint64_t	ft_lowest_index(t_dynarray *darr);
uint64_t	ft_highest_index(t_dynarray *darr);
int			ft_parse_advance(char **argv, int i, int j);
int			ft_index_check(t_dynarray darr);
int			ft_scan(t_dynarray *darr, int old_mid, int mid);
void		ft_insrt_two(t_dynarray *darr, t_dynarray *darr2);
void		ft_five_sort(t_dynarray *darr, t_dynarray *darr2);
int			ft_error(t_dynarray *darr);
int			ft_abs(int nb);
int			ft_is_sorted(t_dynarray *darr);
int			ft_move_lower(t_dynarray *darr, t_dynarray *darr2, int old_mid,
				int mid);
int			ft_parse_string(char **argv, t_dynarray *darr, int j);
int			ft_small_sort(t_dynarray *darr, t_dynarray *darr2, bool cmprt);
int			ft_count_sorted(t_dynarray *darr, bool cmprt);
uint64_t	ft_count_index(t_dynarray *darr, uint64_t index, int nb_sorted);
int			ft_ps_index(t_dynarray *darr);
int			ft_insert_sort(t_dynarray *darr, t_dynarray *darr2);
uint64_t	ft_count_lower(t_dynarray *darr, uint64_t index, int nb_sorted);
uint64_t	ft_count_bigger(t_dynarray *darr, uint64_t index, int nb_sorted);
int			ft_find_middle(t_dynarray *darr, bool cmprt);
int			ft_sort_stack(t_dynarray *darr, t_dynarray *darr2, bool cmprt,
				int mid);
int			ft_ps_atoi(char *nstr);
int			ft_parse(int argc, char **argv, t_dynarray *darr);
int			ft_sw(t_dynarray *darr, bool cmprt);
int			ft_ps(t_dynarray *darr, t_dynarray *darr2, uint64_t n, bool cmprt);
int			ft_rs(t_dynarray *darr, uint64_t n, bool cmprt);
int			ft_rrs(t_dynarray *darr, uint64_t n, bool cmprt);
int			ft_fast_sort3(t_dynarray *darr, bool cmprt);
int			ft_fast_sort2(t_dynarray *darr, bool cmprt);
int			ft_fast_sort(t_dynarray *darr, bool cmprt);

#endif
