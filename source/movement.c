/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:44:56 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/23 15:48:28 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movement(t_swap **a, t_swap **b, t_data *d)
{
	while (d->count_a != 0 && d->count_b != 0)
		rrr_rr(a, b, d);
	while (d->count_a != 0 || d->count_b != 0)
	{
		movement_a(a, d);
		movement_b(b, d);
	}
	pa(a, b);
	// print_lst(*a);
	// print_lst(*b);
}

void	rrr_rr(t_swap **a, t_swap **b, t_data *d)
{
	if(d->count_a > 0 && d->count_b > 0)
	{
		rr(a, b);
		d->count_a--;
		d->count_b--;
	}
	else if (d->count_a < 0 && d->count_b < 0)
	{
		rrr(a, b);
		d->count_a++;
		d->count_b++;
	}
	while (d->count_a != 0 || d->count_b != 0)
	{
		movement_a(a, d);
		movement_b(b, d);
	}
}

void	movement_a(t_swap **a, t_data *d)
{
	if (d->count_a > 0)
	{
		ra(a, 1);
		d->count_a--;
	}
	else if (d->count_a < 0)
	{
		rra(a, 1);
		d->count_a++;
	}
}

void	movement_b(t_swap **b, t_data *d)
{
	if (d->count_b > 0)
	{
		rb(b, 1);
		d->count_b--;
	}
	else if (d->count_b < 0)
	{
		rrb(b, 1);
		d->count_b++;
	}
}

void	final_rotation(t_swap **a)
{
	int	min;
	int pos_min;
	int	i;

	i = 0;
	min = smallest(*a);
	pos_min = cal_index(*a, min, fft_lstsize(*a));
	while (i < ft_abs(pos_min))
	{
		if (pos_min > 0)
			ra(a, 1);
		else
			rra(a, 1);
		i++;
	}
}
