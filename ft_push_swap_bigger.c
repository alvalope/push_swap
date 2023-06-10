/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bigger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:40:39 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/07 12:58:17 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_b_to_a(t_num_list **a, t_num_list **b, int pos)
{
	t_num_list	*aux;

	aux = *b;
	while (aux)
	{
		if (aux->pos == pos)
		{
			ft_do_r_and_rr(a, b, aux);
			ft_push(b, a, "pa");
			break ;
		}
		aux = aux->next;
	}
}

void	ft_ps_bigger3(t_num_list **a, t_num_list **b, t_vars **v)
{
	t_num_list	*aux;
	int			min;
	int			pos;

	ft_check_swap(a, b);
	ft_update_lists(a, b, (*v)->n_n);
	while (*b)
	{
		aux = *b;
		min = ft_total_cost(aux);
		pos = aux->pos;
		while (aux)
		{
			if (ft_total_cost(aux) < min)
			{
				min = ft_total_cost(aux);
				pos = aux->pos;
			}
			aux = aux->next;
		}
		ft_b_to_a(a, b, pos);
		ft_update_lists(a, b, (*v)->n_n);
	}
	ft_check_ind0(a, (*v)->n_n);
}

void	ft_ps_bigger2(t_num_list **a, t_num_list **b, t_vars **v)
{
	int	i;
	int	nums;

	i = 0;
	nums = ft_count_list(*a);
	while (i < nums - 1)
	{
		if ((*a)->nb < (*v)->med1)
		{
			ft_push(a, b, "pb");
			if ((*b)->next)
				ft_rotate(b, "rb");
		}
		else if ((*a)->nb >= (*v)->med3)
		{
			ft_push(a, b, "pb");
			if ((*b)->next && (*b)->nb < (*b)->next->nb)
				ft_check_swap(a, b);
		}
		else
			ft_rotate(a, "ra");
		i++;
	}
}

void	ft_ps_bigger(t_num_list **a, t_num_list **b, t_vars **v)
{
	int			i;

	i = 0;
	while (i < (*v)->n_n)
	{
		if ((*a)->nb >= (*v)->med1 && (*a)->nb < (*v)->med2)
		{
			ft_push(a, b, "pb");
			if ((*b)->next)
				ft_rotate(b, "rb");
		}
		else if ((*a)->nb >= (*v)->med2 && (*a)->nb < (*v)->med3)
		{
			ft_push(a, b, "pb");
			if ((*b)->next && (*b)->nb < (*b)->next->nb)
				ft_check_swap(a, b);
		}
		else
			ft_rotate(a, "ra");
		i++;
	}
	ft_ps_bigger2(a, b, v);
	ft_ps_bigger3(a, b, v);
}

int	ft_push_swap(t_num_list **a, t_num_list **b, int n_n, t_vars **v)
{
	int		ordered;

	ordered = ft_is_ordered(*a);
	if (ordered && !*b)
		return (1);
	else
	{
		if (n_n == 2)
			ft_swap(a, "sa");
		else if (n_n == 3)
			ft_ps_3(a, b, &ordered);
		else if (n_n == 4)
			ft_ps_4(a, b, &ordered);
		else if (n_n == 5)
			ft_ps_5(a, b, &ordered);
		else
		{
			(*v)->n_n = n_n;
			ft_initialize_list(a, n_n);
			ft_ps_bigger(a, b, v);
		}
	}
	return (0);
}
