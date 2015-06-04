/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:31:42 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/04 16:30:13 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstaddend(const void *content, size_t content_size, t_list **plst)
{
	t_list		*alst;

	alst = *plst;
	if (alst)
	{
		while (alst->next != NULL)
			alst = alst->next;
		if (alst->next == NULL)
			alst->next = ft_lstnew(content, content_size);
	}
	else
	{
		*plst = ft_lstnew(content, content_size);
	}
}
