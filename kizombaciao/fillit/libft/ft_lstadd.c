/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchao <cchao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:26:57 by cchao             #+#    #+#             */
/*   Updated: 2019/05/11 09:58:53 by cchao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

/*
** DESCRIPTION:  adding alst to new->next to the front.
** this pointer, still don't understand, why not t_list *alst?
** for example, how would you create an array of pointers to t_list?
** use the analogy of char **av, where you have av[i][j]
** &av[i] represent the addresses to strings
** &av[i][j] represent the addresses to the chars within a selected string
** av is a double pointer.  it is a pointer to a pointer.
** the outside pointer holds
** the address of the inner pointer,
** which holds the address of the var.
** so alst is a pointer that holds
** the address of a pointer that points to a t_list var.
** Adds the element new at the beginning of the list.
*/
