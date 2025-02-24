/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:49:35 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/24 15:21:45 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**matrix_creation(int ac, char **av)
{
	char	**matrix;

	if (ac == 2)
		matrix = two_args(av[1]);
	else
		matrix = more_args(ac, av);
	return (matrix);
}

int	main(int ac, char **av)
{
	char	**matrix;
	t_swap	*a;
	t_swap	*b;
	t_data	d;

	b = NULL;
	if (ac < 2)
		return (write(2, "ERROR\n NO ARGS", 13), 0);
	matrix = matrix_creation(ac, av);
	if (matrix == NULL)
		return (write(2, "ERROR\nMATRIX", 12), 0);
	a = lstcreation(matrix);
	if (!a)
		return (0);
	if (fft_lstsize(a) == 3)
		return (three_args(&a), free_list(a), 0);
	while (a && a->next->next)
		pb(&a, &b);
	two_check(&a);
	push_all(&a, &b, &d);
	final_rotation(&a);
	if (is_sorted(&a) == 0)
		write(2, "ERROR\n", 6);
	return (free_list(a), 0);
}
