/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_prt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:48:44 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/24 18:10:14 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_swap **swap, int i)
{
	t_swap	*last;
	t_swap	*first;

	if(!*swap|| !swap || !(*swap)->next)
		return (-1);
	first = *swap;
	*swap = (*swap)->next;
	first->next = NULL;
	last = lastnode(swap);
	last->next = first;
	// g_move_count++;
	if (i == 1)
		ft_printf("ra\n");
	return(1);
}

int	rb(t_swap **swap, int i)
{
	t_swap	*last;
	t_swap	*first;

	if(!*swap|| !swap || !(*swap)->next)
		return (-1);
	first = *swap;
	*swap = (*swap)->next;
	first->next = NULL;
	last = lastnode(swap);
	last->next = first;
	// g_move_count++;
	if (i == 1)
		ft_printf("rb\n");
	return(1);
}

int	rr(t_swap **a, t_swap **b, int i)
{
	// g_move_count--;
	if((ra(a, 0) != 1) || (rb(b, 0) != 1))
		return(-1);
	else
	{
		if (i == 1)
			ft_printf("rr\n");
		return (1);
	}
}
