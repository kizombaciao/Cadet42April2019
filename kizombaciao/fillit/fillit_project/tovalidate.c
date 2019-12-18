/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tovalidate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:40:13 by sako              #+#    #+#             */
/*   Updated: 2019/06/11 22:08:38 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		CHECK1 check BLOCK(#)
**		CHECK2 check BLOCK(.)
**		CHECK3 check NL(\n) <<=  new line
**		CHECK4 check all 1, 2, 3
*/

/*
** 		Checks for any invalid characters
** 		Checks for wrong-length lines ('\n' in an invalid position)
*/

int		check_valid_char_lenght_line(char *buf, int byte, int line)
{
	int		n;

	n = byte + line;
	if (!CHECK4(buf[n]))
		return (1);
	if ((line + 1) % 5 == 0 && !CHECK3(buf[byte + line]))
		return (1);
	return (0);
}

/*
** 		Counts number of '#' characters (Must be 4)
** 		Checks each '#' character to see if it's adjacent to another(6 ~ 8)
*/

int		check_pieces(char *buf, int byte, int line, int *adj_count)
{
	int		count;

	count = 0;
	if (CHECK1(buf[byte + line]))
	{
		if (byte + line - 1 >= byte && CHECK1(buf[byte + line - 1]))
			*adj_count += 1;
		if (byte + line + 1 < byte + 19 && CHECK1(buf[byte + line + 1]))
			*adj_count += 1;
		if (byte + line - 5 >= byte && CHECK1(buf[byte + line - 5]))
			*adj_count += 1;
		if (byte + line + 5 < byte + 19 && CHECK1(buf[byte + line + 5]))
			*adj_count += 1;
		count++;
	}
	return (count);
}

/*
**		1. Checks if adjacent number is 6 ~ 8 and there are 4 pieces.
**		2. Checks for '\n' at end of piece block
*/

int		check_piece_num_connection(int adj_count, int count)
{
	if (adj_count < 6 || adj_count > 8 || count != 4)
		return (1);
	return (0);
}

/*
**		Checks for '\n' at end of piece block
*/

int		check_endline(char *buf, int size, int byte, int line)
{
	if ((byte + line != size) && !CHECK3(buf[byte + line]))
		return (1);
	return (0);
}

/*
**		return 0 if input blocks are valid, otherwise return 1.
*/

int		tovalidate(char *buf, int size)
{
	int		i;
	int		j;
	int		count;
	int		adj_count;

	i = 0;
	while (i <= size)
	{
		j = -1;
		count = 0;
		adj_count = 0;
		while (++j < 20)
		{
			if (check_valid_char_lenght_line(buf, i, j))
				return (1);
			count += check_pieces(buf, i, j, &adj_count);
		}
		if (check_piece_num_connection(adj_count, count) || \
			check_endline(buf, size, i, j))
			return (1);
		i += 21;
	}
	return (0);
}
