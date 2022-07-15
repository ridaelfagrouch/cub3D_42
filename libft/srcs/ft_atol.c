/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavos <bavos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:31:10 by bavos             #+#    #+#             */
/*   Updated: 2022/07/15 16:31:13 by bavos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* -------------------------------------------------------------------------- */

long	ft_atol(const char *str)
{
	char	sign;
	long	sum;
	int		i;

	i = 0;
	sum = 0;
	sign = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i] - '+';
	while (ft_isdigit(str[i]))
		sum = (sum * 10) + (str[i++] - '0');
	if (sign)
		sum *= -1;
	return (sum);
}

/* -------------------------------------------------------------------------- */
