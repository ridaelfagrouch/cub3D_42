/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavos <bavos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:10:32 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/07/15 16:32:30 by bavos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	x;

	i = 0;
	x = (char) c;
	str = (char *) s;
	while (str[i] >= 0)
	{
		if (str[i] == x)
			return (&str[i]);
		else if (str[i] == 0)
			break ;
		i++;
	}
	return (0);
}
