/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:09 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:30:32 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb <= -10 || nb >= 10)
		ft_putnbr(nb / 10);
	if (nb < 0)
	{
		if (nb >= -9)
			ft_putchar('-');
		ft_putchar('0' - (nb % 10));
	}
	else
	{
		ft_putchar('0' + (nb % 10));
	}
}

/*
** USE THIS FOR EXAM STUDY !!!
**
** void ft_putnbr(int nb)
** {
**     if (nb <= -2147483648)
**     {
**         ft_putstr("-2147483648");
**         return ;
**     }
**     if (nb < 0)
**     {
**         ft_putchar('-');
**         nb *= -1;
**     }
**     if (nb >= 10)
**         ft_putnbr(nb / 10);
**     ft_putchar((nb % 10) + '0');
** }
*/
