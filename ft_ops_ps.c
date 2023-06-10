/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:19:14 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 10:19:59 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_num_list **l, char *op)
{
	int	aux;
	int	aux_ind;

	if (l[0] && l[0]->next)
	{
		aux = l[0]->nb;
		aux_ind = l[0]->ind;
		l[0]->nb = l[0]->next->nb;
		l[0]->ind = l[0]->next->ind;
		l[0]->next->nb = aux;
		l[0]->next->ind = aux_ind;
	}
	ft_printf("%s\n", op);
}

void	ft_swaps(t_num_list **a, t_num_list **b, char *op)
{
	int	aux;
	int	aux_ind;

	if (a[0] && a[0]->next)
	{
		aux = a[0]->nb;
		aux_ind = a[0]->ind;
		a[0]->nb = a[0]->next->nb;
		a[0]->ind = a[0]->next->ind;
		a[0]->next->nb = aux;
		a[0]->next->ind = aux_ind;
	}
	if (b[0] && b[0]->next)
	{
		aux = b[0]->nb;
		aux_ind = b[0]->ind;
		b[0]->nb = b[0]->next->nb;
		b[0]->ind = b[0]->next->ind;
		b[0]->next->nb = aux;
		b[0]->next->ind = aux_ind;
	}
	ft_printf("%s\n", op);
}

void	ft_push(t_num_list **l1, t_num_list **l2, char *op)
{
	int			aux;
	int			ind;
	t_num_list	*tmp;

	if (l1)
	{
		aux = l1[0]->nb;
		ind = l1[0]->ind;
		ft_lst_add_front(l2, aux, ind);
		tmp = l1[0];
		l1[0] = l1[0]->next;
		free(tmp);
	}
	ft_printf("%s\n", op);
}
