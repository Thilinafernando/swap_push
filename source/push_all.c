/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:46:15 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/24 18:15:05 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_args(t_swap **a)
{
	if ((*a)->content > (*a)->next->content
	&& (*a)->next->content > (*a)->next->next->content)
	{
		sa(*a, 1);
		rra(a, 1);
	}
	else if ((*a)->next->content > (*a)->content
	&& (*a)->content > (*a)->next->next->content)
	rra(a, 1);
	else if ((*a)->content > (*a)->next->next->content
	&& (*a)->next->next->content > (*a)->next->content)
	ra(a, 1);
	else if ((*a)->next->content > (*a)->next->next->content
	&& (*a)->next->next->content > (*a)->content)
	{
		sa(*a, 1);
		ra(a, 1);
	}
	else if ((*a)->next->next->content > (*a)->content
	&& (*a)->content > (*a)->next->content)
	sa(*a, 1);
}

int	is_sorted(t_swap **a)
{
	t_swap *tmp;

	tmp = *a;
	while(tmp->next)
	{
		if (tmp->content > tmp->next->content)
		return(0);
		tmp = tmp->next;
	}
	return (1);
}

void		two_check(t_swap **a)
{
	t_swap	*tmp;

	tmp = *a;
	if (tmp->content > tmp->next->content)
	sa(*a, 1);
}

void	push_all(t_swap **a, t_swap **b, t_data *d)
{
	while (*b)
	{
		best_element(a, b, d);
		// printf("\n %d  %d \n", d->count_a, d->count_b);
		movement(a, b, d);
	}
}
