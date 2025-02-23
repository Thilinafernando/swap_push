/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:31 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/23 15:54:53 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*fft_lstnew(int	content)
{
	t_swap	*newnode;

	newnode = (t_swap *)malloc(sizeof(t_swap));
	if (newnode == NULL)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}

void	free_list(t_swap *swap)
{
	t_swap	*tmp;

	while(swap)
	{
		tmp = swap;
		swap = swap->next;
		free(tmp);
	}
}
void	free_one(t_swap **swap)
{
	t_swap *tmp;

	if (swap && *swap)
	{
		tmp = *swap;
		*swap = tmp->next;
		free(tmp);
	}
}

void	print_lst(t_swap *swap)
{
	t_swap	*tmp;
	tmp = swap;
	while (tmp)
	{
		if(tmp->next == NULL)
		{
			ft_printf("%d\n",tmp -> content);
			break;
		}
		ft_printf("%d--",tmp -> content);
		tmp = tmp -> next;
	}
}

t_swap *lastnode(t_swap **swap)
{
	t_swap *tmp;

	if (!swap || !*swap)
		return (NULL);
	tmp = *swap;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

