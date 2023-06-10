/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:49:05 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/07 12:43:36 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ps_3(t_num_list **a, t_num_list **b, int *ordered)
{
	if ((*a)->next->next->nb > (*a)->next->nb
		&& (*a)->next->next->nb > (*a)->nb)
		ft_swap(a, "sa");
	else if ((*a)->next->nb > (*a)->next->next->nb
		&& (*a)->next->nb > (*a)->nb)
		ft_reverse_rotate(a, "rra");
	else if ((*a)->nb > (*a)->next->nb
		&& (*a)->nb > (*a)->next->next->nb)
		ft_rotate(a, "ra");
	*ordered = ft_is_ordered(*a);
	if (!*ordered)
		ft_swap(a, "sa");
	*ordered = ft_is_ordered(*a);
	if (!*ordered)
		ft_ps_3(a, b, ordered);
}

void	ft_ps_4(t_num_list **a, t_num_list **b, int *ordered)
{
	if ((*a)->nb > (*a)->next->nb)
		ft_swap(a, "sa");
	if ((*a)->next->nb > ft_lst_before_last(*a)->nb
		&& (*a)->next->nb > ft_lst_last(*a)->nb
		&& (*a)->nb > ft_lst_before_last(*a)->nb
		&& (*a)->nb > ft_lst_last(*a)->nb)
	{
		ft_rotate(a, "ra");
		ft_rotate(a, "ra");
		ft_ps_4(a, b, ordered);
	}
	*ordered = ft_is_ordered(*a);
	if (!*ordered)
	{
		ft_push(a, b, "pb");
		ft_ps_3(a, b, ordered);
		ft_push(b, a, "pa");
		*ordered = ft_is_ordered(*a);
		if (!*ordered)
			ft_swap(a, "sa");
	}
}

void	ft_ps_5a(t_num_list **a, t_num_list **b, int *ordered)
{
	if ((*a)->nb < (*a)->next->next->nb
		&& (*a)->nb < ft_lst_before_last(*a)->nb
		&& (*a)->nb < ft_lst_last(*a)->nb)
	{
		ft_push(a, b, "pb");
		ft_ps_4(a, b, ordered);
		ft_push(b, a, "pa");
	}
	else if (ft_lst_last(*a)->nb < ft_lst_before_last(*a)->nb
		&& ft_lst_last(*a)->nb < (*a)->next->next->nb
		&& ft_lst_last(*a)->nb < (*a)->nb)
	{
		ft_reverse_rotate(a, "rra");
		ft_push(a, b, "pb");
		ft_ps_4(a, b, ordered);
		ft_push(b, a, "pa");
	}
	else
	{
		ft_rotate(a, "ra");
		ft_rotate(a, "ra");
	}
}

void	ft_ps_5b(t_num_list **a, t_num_list **b, int *ordered)
{
	if ((*a)->nb > (*a)->next->nb)
		ft_swap(a, "sa");
	if (!ft_is_ordered(*a))
	{
		ft_push(a, b, "pb");
		ft_ps_4(a, b, ordered);
		ft_push(b, a, "pa");
		if ((*a)->nb > (*a)->next->nb)
			ft_swap(a, "sa");
	}
}

void	ft_ps_5(t_num_list **a, t_num_list **b, int *ordered)
{
	if ((*a)->nb > (*a)->next->nb)
		ft_swap(a, "sa");
	if ((*a)->next->nb > (*a)->next->next->nb
		&& (*a)->next->nb > ft_lst_before_last(*a)->nb
		&& (*a)->next->nb > ft_lst_last(*a)->nb)
	{
		ft_ps_5a(a, b, ordered);
	}
	else if (ft_lst_before_last(*a)->nb > ft_lst_last(*a)->nb
		&& ft_lst_before_last(*a)->nb > (*a)->next->nb
		&& ft_lst_before_last(*a)->nb > (*a)->next->next->nb)
		ft_reverse_rotate(a, "rra");
	if (!ft_is_ordered(*a))
	{
		ft_ps_5b(a, b, ordered);
	}
	*ordered = ft_is_ordered(*a);
	if (!*ordered)
		ft_ps_5(a, b, ordered);
}
