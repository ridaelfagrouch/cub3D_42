/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavos <bavos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:33:38 by bavos             #+#    #+#             */
/*   Updated: 2022/07/15 16:33:42 by bavos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* -------------------------------------------------------------------------- */

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] || needle[j] == '\0')
			if (needle[j++] == '\0')
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */
