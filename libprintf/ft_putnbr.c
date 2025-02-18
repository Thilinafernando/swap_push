/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:52:42 by tkurukul          #+#    #+#             */
/*   Updated: 2024/12/03 18:23:36 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	motor(char *str, int f, int nb)
{
	int	i;
	int	count;

	i = f;
	count = 0;
	while (nb > 9)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
		count++;
	}
	str[i] = (nb + 48);
	str[i + 1] = '\0';
	while (i >= 0 && str[i] != '-')
	{
		write(1, &str[i], 1);
		i--;
	}
	if (str[0] == '-')
		count++;
	return (count + 1);
}

int	ft_putnbr(int nb)
{
	int		i;
	char	str[24];

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		str[i] = '-';
		i++;
		nb = -nb;
	}
	i = motor(str, i, nb);
	return (i);
}
/*int main() {
  printf("\n%d\n", ft_putnbr(-21474836));
  return 0;
}*/
