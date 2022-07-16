/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:23:10 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/07/16 03:12:20 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*root;
	t_list	*ptr;

	root = NULL;
	ptr = *lst;
	if (!*lst)
		*lst = NULL;
	while (ptr != NULL)
	{
		root = ptr;
		del(root->content);
		ptr = ptr -> next;
		free(root);
	}
	*lst = NULL;
}
