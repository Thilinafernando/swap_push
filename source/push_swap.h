/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:09:02 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/24 15:32:01 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libprintf/ft_printf.h"

// extern int g_move_count;

typedef struct s_swap
{
	int				content;
	struct s_swap	*next;
} t_swap;

typedef struct s_data
{
	int				count_a;
	int				count_b;
	int				total;
} t_data;

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

t_swap		*fft_lstnew(int	content);
void		free_list(t_swap *swap);
void		print_lst(t_swap *swap);
void		free_one(t_swap **swap);
t_swap		*lastnode(t_swap **swap);
t_swap		*lastnode1(t_swap **swap);
int			sa(t_swap *swap);
int			sb(t_swap *swap);
int			ss(t_swap *a, t_swap *b);
int			pa(t_swap **a, t_swap **b);
int			pb(t_swap **a, t_swap **b);
int			ra(t_swap **swap, int i);
int			rb(t_swap **swap, int i);
int			rr(t_swap **a, t_swap **b);
int			rra(t_swap **swap, int i);
int			rrb(t_swap **swap, int i);
int			rrr(t_swap **a, t_swap **b);
int			cal_index(t_swap *a, int n, int size);
int			smallest(t_swap *swap);
int			ft_abs(int x);
int			fft_lstsize(t_swap *lst);
void		fft_lstadd_back(t_swap **lst, t_swap *new);
void		free_mat(char **matrix);
char		**more_args(int argc, char **av);
char		**two_args(char *argv);
int			duplicates(char **matrix);
int			check_arg(char **matrix);
t_swap		*lstcreation(char **matrix);
int			moves_b(t_swap *b, int i);
int			moves_a(t_swap *a, int n);
void		store_data(int total, int count_a, int count_b, t_data *d);
void		total_moves(t_swap *a, t_swap *b, int pos, t_data *d);
void		best_element(t_swap **a, t_swap **b, t_data *d);
void		movement(t_swap **a, t_swap **b, t_data *d);
void		movement_a(t_swap **a, t_data *d);
void		movement_b(t_swap **b, t_data *d);
void		final_rotation(t_swap **a);
int			is_sorted(t_swap **a);
void		two_check(t_swap **a);
int			ft_strcmp(const char *s1, const char *s2);
void		push_all(t_swap **a, t_swap **b, t_data *d);
void		three_args(t_swap **a);

#endif
