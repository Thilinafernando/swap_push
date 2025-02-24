/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:32:08 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/24 19:27:59 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

int	operations(t_swap *a, t_swap *b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(&a, &b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(&a, &b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(&a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(&b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(&a, &b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(&a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(&b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(&a, &b, 0);
	else
		return (write(2, "ERROR\n", 6), 0);
	return (1);
}

void	last(t_swap *a)
{
	if (a && is_sorted(&a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	char	**matrix;
	char	*str;
	t_swap	*a;
	t_swap	*b;

	b = NULL;
	if (ac < 2)
		return (write(2, "ERROR\n", 6), 0);
	matrix = matrix_creation(ac, av);
	if (matrix == NULL)
		return (write(2, "ERROR\n", 6), 0);
	a = lstcreation(matrix);
	if (!a)
		return (0);
	str = get_next_line(0);
	while (str)
	{
		if (operations(a, b, str) == 0)
			return (free_list(a), free_list(b), free(str), 0);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return(last(a), 0);
	return (free_list(a), free_list(b), 0);
}
