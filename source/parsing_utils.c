/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:47:34 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/21 22:49:40 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **matrix)
{
	int	i;
	int	j;

	j = 0;
	while (matrix[j])
	{
		i = 0;
		if (matrix[j][i] == '+' || matrix[j][i] == '-')
			i++;
		while (matrix[j][i])
		{
			if(matrix[j][i] >= '0' && matrix[j][i] <= '9')
				i++;
			else
			{
				write(2, "ERROR\nARGS NOT VALID", 20);
				return(0);
			}
		}
		j++;
	}
	return (1);
}
int	duplicates(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = i + 1;
		while (matrix[j])
		{
			if (ft_strcmp(matrix[i], matrix[j]) == 0)
			{
				write(2, "ERROR\nDUPS FOUND", 16);
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
char	**two_args(char *argv)
{
	char	**matrix;

	matrix = ft_split(argv, 32);
	if (check_arg(matrix) == 0 || duplicates(matrix) == 0)
		return (NULL);
	return (matrix);
}
char	**more_args(int argc, char **av)
{
	int	j;
	int	i;
	char	**matrix;

	i = 1;
	j = 0;
	matrix = malloc((argc) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (i < argc)
	{
		matrix[j] = ft_strdup(av[i]);
		if (!matrix[j])
			return (free_mat(matrix), NULL);
		i++;
		j++;
	}
	matrix[j] = NULL;
	if (check_arg(matrix) == 0 || duplicates(matrix) == 0)
		return (free_mat(matrix), NULL);
	return(matrix);
}

t_swap	*lstcreation(char **matrix)
{
	int		i;
	int	check;
	t_swap	*new_node;
	t_swap	*head;

	i = 0;
	new_node = NULL;
	while (matrix[i])
	{
		check = ft_atoi(matrix[i]);
		if (check > INT_MAX || check < INT_MIN)
			return (free_mat(matrix), NULL);
		new_node = fft_lstnew((int)check);
		if (!new_node)
			return(free_mat(matrix), free_list(head), NULL);
		if (i == 0)
			head = new_node;
		else
			fft_lstadd_back(&head, new_node);
		i++;
	}
	free_mat(matrix);
	return (head);
}
void		two_check(t_swap **a)
{
	t_swap	*tmp;

	tmp = *a;
	if (tmp->content > tmp->next->content)
		sa(*a);
}
