/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:30:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/18 17:22:07 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_a(t_swap *a, int pos_a)
{
	int	ls_size;

	ls_size = fft_lstsize(a);
	if (pos_a > (ls_size / 2))
		return(ls_size - pos_a);
	return (pos_a);
}

int	moves_b(t_swap *b, int i)
{
	int	ls_size;

	ls_size = fft_lstsize(b);
	if(i > (ls_size / 2))
		return(ls_size - i);
	return (i);
}

int	total_moves(t_swap *a, t_swap *b, int pos)
{
	int	count_a;
	int	count_b;
	int	pos_a;
	int	size_a;
	int	size_b;

	size_a = fft_lstsize(a);
	size_b = fft_lstsize(b);
	pos_a = index_a(a, b->content);
	count_a = moves_a(a, pos_a);
	//printf("%dcount a\n", count_a);
	count_b = moves_b(b, pos);
	if (((pos < (size_b / 2)) && (pos_a < (size_a / 2))) || ((pos >= (size_b / 2)) && (pos_a >= (size_a / 2))))
	{
		if(count_a > count_b)
			return (count_a);
		return (count_b);
	}
	else
		return (count_a + count_b);
}

int	best_element(t_swap *a, t_swap *b)
{
	int	i;
	int	min_move;
	int	moves;
	int	index;
	t_swap	*tmp;
	

	tmp = b;
	min_move = 999999;
	index = 0;
	i = 0;
	while(tmp)
	{
		moves = total_moves(a, tmp, i);
		printf("%d\n", moves);
		if(moves < min_move)
		{
			min_move = moves;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	printf("%d\n", index);
	return (index);
}
void	movement_b(t_swap **b, int index)
{
	int size;

	size = fft_lstsize(*b);
	if (index == 0)
		return;
	if (index >= (size / 2))
	{
		while(index < size)
		{
			rrb(b);
			index++;
		}
	}
	else
		{
			while(index > 0)
			{
				rb(b);
				index--;
			}
		}

}
void	movement_a(t_swap **a, int pos_a)
{
	int size;

	size = fft_lstsize(*a);
	if(pos_a == 0)
		return ;
	if (pos_a >= size/ 2)
	{
		while(pos_a < size)
		{
			rra(a);
			pos_a++;
		}
	}
	else
	{
		while(pos_a > 0)
		{
			ra(a);
			pos_a--;
		}
	}
		return ;
}
void	rr_movement(t_swap **a, t_swap ** b, t_data *d)
{
	while (d->pos_a > 0 && d->index > 0 && d->pos_a < d->size_a / 2 && d->index < d->size_b / 2)
	{
		rr(a, b);
		d->pos_a--;
		d->index--;
	}
}
void	rrr_movement(t_swap **a, t_swap ** b, t_data *d)
{
	while (d->pos_a > 0 && d->index > 0 && d->pos_a > d->size_a / 2 && d->index > d->size_b / 2)
	{
		rrr(a, b);
		d->pos_a++;
		d->index++;
	}
}

void	movement(t_swap **a, t_swap **b, t_data *d)
{
	t_swap	*tem;
	int	tmp;

	d->size_a = fft_lstsize(a);
	d->size_b = fft_lstsize(b);
	tmp = d->index;
	tem = *b;
	while(tmp > 0 && tem)
	{
		tem = tem->next;
		tmp--;
	}
	d->pos_a = index_a(*a, tem->content);
	if (((d->index < (d->size_b / 2)) && (d->pos_a < (d->size_a / 2))))
		rr_movement(a, b, d);
	else if (((d->index > (d->size_b / 2)) && (d->pos_a > (d->size_a / 2))))
		rrr_movement(a, b, d);
	movement_b(b, d->index);
	movement_a(a, d->pos_a);
	pa(a, b);
}
void	push_all(t_swap **a, t_swap **b)
{
	t_data	d;

	while(*b)
	{
		d.index = best_element(*a, *b);
		ft_printf("Before movement:\nA: ");
		print_lst(*a);
		ft_printf("\nB: ");
		print_lst(*b);
		ft_printf("\n");
		movement(a, b, &d);
		ft_printf("After movement:\nA: ");
		print_lst(*a);
		ft_printf("\nB: ");
		print_lst(*b);
		ft_printf("\n");
	}
}
int	main(void)
{
	t_swap	*head = fft_lstnew(89);
	t_swap	*h2 = fft_lstnew(104);
	// t_swap	*h3 = fft_lstnew(94);
	// t_swap	*h4 = fft_lstnew(52);
	// t_swap	*h5 = fft_lstnew(104);
	// t_swap	*h6 = fft_lstnew(90);
	// t_swap	*h7 = fft_lstnew(60);
	// t_swap	*h8 = fft_lstnew(82);

	t_swap	*head2 = fft_lstnew(1);
	t_swap	*h12 = fft_lstnew(44);
	t_swap	*h13 = fft_lstnew(60);
	t_swap	*h14 = fft_lstnew(99);

	head->next = h2;
	// h2->next = h3;
	// h3->next = h4;
	// h4->next = h5;
	// h5->next = h6;
	// h6->next = h7;
	// h7->next = h8;

	head2->next = h12;
	h12->next = h13;
	h13->next = h14;

	// sa(head);
	//sb(head2);
	//ss(head, head2);
	//pa(&head, &head2);
	//pb(&head, &head2);
	//ra(&head);
	//rb(&head2);
	//rr(&head, &head2);
	//rra(&head);
	//rrr(&head, &head2);
	ft_printf("Before\n");
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	ft_printf("After\n");
	push_all(&head, &head2);
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	free_list(head2);
	free_list(head);
}
