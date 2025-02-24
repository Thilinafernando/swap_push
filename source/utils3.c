/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:53:13 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/24 18:57:55 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	cal_index(t_swap *a, int n, int size)
{
	int		i;
	t_swap	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->content == n && i <= size / 2)
			return (i);
		else if (tmp->content == n && i > size / 2)
			return (i - size);
		i++;
		tmp = tmp->next;
	}
	return(-555);
}

void	free_mat(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return (free(matrix));
	while (matrix[i] != NULL)
		i++;
	if (matrix[i] == NULL)
		i--;
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	return ;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	**matrix_creation(int ac, char **av)
{
	char	**matrix;

	if (ac == 2)
		matrix = two_args(av[1]);
	else
		matrix = more_args(ac, av);
	return (matrix);
}
