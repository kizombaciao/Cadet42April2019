/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:46:56 by cchao             #+#    #+#             */
/*   Updated: 2019/08/07 10:49:02 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove the extension (type) of a filename, returning its basename.
*/

char	*ft_remove_extension(char *filename)
{
	char	*base_name;
	char	*dot;
	char	*sep;

	if (!filename)
		return (NULL);
	if (!(base_name = (char *)malloc(sizeof(char) * ft_strlen(filename) + 1)))
		return (NULL);
	ft_strcpy(base_name, filename);
	if ((dot = ft_strrchr(base_name, '.')))
	{
		if ((sep = ft_strrchr(base_name, '/')))
			(sep < dot) ? *dot = '\0' : *dot;
		else
			*dot = '\0';
	}
	return (base_name);
}
