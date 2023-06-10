/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:03:47 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/06 11:55:38 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_num_list	*ft_lst_new(int content)
{
	t_num_list	*l;

	l = ft_calloc(sizeof(t_num_list), 1);
	if (!l)
		return (0);
	else
	{
		l->nb = content;
		l->next = 0;
		return (l);
	}
}

t_num_list	*ft_lst_last(t_num_list *lst)
{
	t_num_list	*aux;

	if (!lst)
		return (0);
	else
	{
		aux = lst;
		while (aux->next)
			aux = aux->next;
		return (aux);
	}
}

t_num_list	*ft_lst_before_last(t_num_list *lst)
{
	t_num_list	*aux;

	if (!lst)
		return (0);
	else
	{
		aux = lst;
		while (aux->next->next)
			aux = aux->next;
		return (aux);
	}
}

void	ft_lst_add_front(t_num_list **lst, int nb, int ind)
{
	t_num_list	*new;

	new = ft_lst_new(nb);
	new->ind = ind;
	new->next = lst[0];
	lst[0] = new;
}

void	ft_lst_add(t_num_list **lst, int nb)
{
	t_num_list	*aux;

	if (!lst[0])
		lst[0] = ft_lst_new(nb);
	else
	{
		aux = ft_lst_last(lst[0]);
		aux->next = ft_lst_new(nb);
	}
}
