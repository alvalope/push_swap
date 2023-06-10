/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:58 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 11:40:16 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_get_quarters(t_num_list *lst, t_vars **v)
{
	(*v)->max = lst->nb;
	(*v)->min = lst->nb;
	lst = lst->next;
	while (lst)
	{
		if (lst->nb < (*v)->min)
			(*v)->min = lst->nb;
		else if (lst->nb > (*v)->max)
			(*v)->max = lst->nb;
		lst = lst->next;
	}
	(*v)->med1 = (*v)->min + (((*v)->max - (*v)->min) / 4);
	(*v)->med3 = (*v)->max - (((*v)->max - (*v)->min) / 4);
	(*v)->med2 = (*v)->min + (((*v)->max - (*v)->min) / 2);
}

int	ft_is_ordered(t_num_list *lst)
{
	int	ordered;
	int	i;

	i = 0;
	ordered = 1;
	while (lst && lst->next)
	{
		if (lst->nb < lst->next->nb)
			lst = lst->next;
		else
		{
			ordered = 0;
			break ;
		}
		i++;
	}
	return (ordered);
}

void	ft_check_swap(t_num_list **a, t_num_list **b)
{
	if (*b && (*b)->next && (*b)->nb < (*b)->next->nb)
	{
		if (*a && (*a)->next && (*a)->nb > (*a)->next->nb)
			ft_swaps(a, b, "ss");
		else
			ft_swap(b, "sb");
	}
	else if (*a && (*a)->next && (*a)->nb > (*a)->next->nb)
		ft_swap(a, "sa");
}

int	ft_total_cost(t_num_list *lst)
{
	int	min;

	if (lst->cost_a < 0 && lst->cost_b < 0)
		min = -lst->cost_a - lst->cost_b;
	else if (lst->cost_a < 0 && lst->cost_b >= 0)
		min = lst->cost_b - lst->cost_a;
	else if (lst->cost_a >= 0 && lst->cost_b < 0)
		min = lst->cost_a - lst->cost_b;
	else
		min = lst->cost_a + lst->cost_b;
	return (min);
}

void	ft_check_ind0(t_num_list **a, int n_n)
{
	int	aux;

	aux = (*a)->ind;
	if ((*a)->ind <= n_n / 2)
	{
		while (aux > 0)
		{
			ft_reverse_rotate(a, "rra");
			aux--;
		}
	}
	else
	{
		while (aux < n_n)
		{
			ft_rotate(a, "ra");
			aux++;
		}
	}
}
