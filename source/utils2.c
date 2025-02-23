/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:51:34 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/23 15:54:35 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*lastnode1(t_swap **swap)
{
	t_swap	*tmp;

	tmp = *swap;
	if(!tmp || !tmp->next)
		return (NULL);
	while(tmp->next->next)
		tmp = tmp->next;
	return(tmp);
}

int	smallest(t_swap *swap)
{
	int		min;
	t_swap	*tmp;

	tmp = swap;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	fft_lstsize(t_swap *lst)
{
	t_swap	*tmp;
	int	i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	fft_lstadd_back(t_swap **lst, t_swap *new)
{
	t_swap	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = new;
}

void	swap_conent(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
