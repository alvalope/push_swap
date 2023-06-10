/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:05:12 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/02 13:37:06 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate(t_num_list **l, char *op)
{
	t_num_list	*last;
	t_num_list	*aux;

	if (l[0] && l[0]->next)
	{
		last = ft_lst_last(l[0]);
		aux = l[0];
		l[0] = aux->next;
		aux->next = 0;
		last->next = aux;
	}
	ft_printf("%s\n", op);
}

void	ft_rotate_both(t_num_list **a, t_num_list **b, char *op)
{
	t_num_list	*last;
	t_num_list	*aux;

	if (a[0] && a[0]->next)
	{
		last = ft_lst_last(a[0]);
		aux = a[0];
		a[0] = aux->next;
		aux->next = 0;
		last->next = aux;
	}
	if (b[0] && b[0]->next)
	{
		last = ft_lst_last(b[0]);
		aux = b[0];
		b[0] = aux->next;
		aux->next = 0;
		last->next = aux;
	}
	ft_printf("%s\n", op);
}

void	ft_reverse_rotate(t_num_list **l, char *op)
{
	t_num_list	*last;
	t_num_list	*before_last;

	if (l[0] && l[0]->next)
	{
		before_last = ft_lst_before_last(l[0]);
		last = ft_lst_last(l[0]);
		before_last->next = 0;
		last->next = l[0];
		l[0] = last;
	}
	ft_printf("%s\n", op);
}

void	ft_reverse_both(t_num_list **a, t_num_list **b, char *op)
{
	t_num_list	*last;
	t_num_list	*before_last;

	if (a[0] && a[0]->next)
	{
		before_last = ft_lst_before_last(a[0]);
		last = ft_lst_last(a[0]);
		before_last->next = 0;
		last->next = a[0];
		a[0] = last;
	}
	if (b[0] && b[0]->next)
	{
		before_last = ft_lst_before_last(b[0]);
		last = ft_lst_last(b[0]);
		before_last->next = 0;
		last->next = b[0];
		b[0] = last;
	}
	ft_printf("%s\n", op);
}
