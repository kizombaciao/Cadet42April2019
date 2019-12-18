/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:46:44 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 10:49:02 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string msg to the standard output followed by an exit of the
** program with a custom return value (defined by ret).
*/

void	ft_puterror(char *msg, int ret)
{
	ft_putendl(msg);
	exit(ret);
}
