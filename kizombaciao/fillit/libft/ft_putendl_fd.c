/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:28:00 by cchao             #+#    #+#             */
/*   Updated: 2019/05/10 19:26:01 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t l;

	l = ft_strlen(s);
	write(fd, s, l);
	ft_putchar_fd('\n', fd);
}

/*
** Outputs the string s to the file descriptor fd followed by a ’\n’.
*/
