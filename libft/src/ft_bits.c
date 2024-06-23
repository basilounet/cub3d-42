/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:48:32 by bvasseur          #+#    #+#             */
/*   Updated: 2024/06/23 13:52:41 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	switch_bit(int nb)
{
	int	rev;
	int	len;

	rev = 0;
	len = 31;
	while (len >= 0)
	{
		rev += ((nb >> len) & 1) ^ 1;
		if (len > 0)
			rev <<= 1;
		len--;
	}
	return (rev);
}
