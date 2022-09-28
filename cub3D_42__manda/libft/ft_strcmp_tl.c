/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_tl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:32:49 by bavos             #+#    #+#             */
/*   Updated: 2022/07/16 03:47:32 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_tl(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			break ;
		i++;
	}
	return ((unsigned char)ft_tolower(s1[i]) - \
		(unsigned char)ft_tolower(s2[i]));
}
