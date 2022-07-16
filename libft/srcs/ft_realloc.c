/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavos <bavos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:32:13 by bavos             #+#    #+#             */
/*   Updated: 2022/07/15 16:32:17 by bavos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* -------------------------------------------------------------------------- */

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = ft_calloc(1, new_size);
	if (new_ptr == NULL)
		return (old_ptr);
	new_ptr = ft_memmove(new_ptr, old_ptr, old_size);
	return (free(old_ptr), new_ptr);
}

/* -------------------------------------------------------------------------- */
