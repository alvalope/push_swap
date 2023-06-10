/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_r_and_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:33:43 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/07 12:58:28 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_rr(t_num_list **a, t_num_list **b, t_num_list *aux)
{
	while (aux->cost_a > 0 && aux->cost_b > 0)
	{
		ft_reverse_both(a, b, "rrr");
		aux->cost_a += 1;
		aux->cost_b += 1;
	}
	while (aux->cost_a < 0 || aux->cost_b < 0)
	{
		if (aux->cost_a < 0)
		{
			ft_reverse_rotate(a, "rra");
			aux->cost_a += 1;
		}
		else if (aux->cost_b < 0)
		{
			ft_reverse_rotate(b, "rrb");
			aux->cost_b += 1;
		}
	}
}

void	ft_do_r(t_num_list **a, t_num_list **b, t_num_list *aux)
{
	while (aux->cost_a > 0 && aux->cost_b > 0)
	{
		ft_rotate_both(a, b, "rr");
		aux->cost_a -= 1;
		aux->cost_b -= 1;
	}
	while (aux->cost_a > 0 || aux->cost_b > 0)
	{
		if (aux->cost_a > 0)
		{
			ft_rotate(a, "ra");
			aux->cost_a -= 1;
		}
		else if (aux->cost_b > 0)
		{
			ft_rotate(b, "rb");
			aux->cost_b -= 1;
		}
	}
}

void	ft_do_rrx(t_num_list **lst, t_num_list *aux, char *op)
{
	if (op[2] == 'a')
	{
		while (aux->cost_a < 0)
		{
			ft_reverse_rotate(lst, "rra");
			aux->cost_a += 1;
		}
	}
	else if (op[2] == 'b')
	{
		while (aux->cost_b < 0)
		{
			ft_reverse_rotate(lst, "rrb");
			aux->cost_b += 1;
		}
	}
}

void	ft_do_rx(t_num_list **lst, t_num_list *aux, char *op)
{
	if (op[1] == 'a')
	{
		while (aux->cost_a > 0)
		{
			ft_rotate(lst, op);
			aux->cost_a -= 1;
		}
	}
	else if (op[1] == 'b')
	{
		while (aux->cost_b > 0)
		{
			ft_rotate(lst, op);
			aux->cost_b -= 1;
		}
	}
}

void	ft_do_r_and_rr(t_num_list **a, t_num_list **b, t_num_list *aux)
{
	if (aux->cost_a < 0 && aux->cost_b < 0)
		ft_do_rr(a, b, aux);
	else if (aux->cost_a > 0 && aux->cost_b > 0)
		ft_do_r(a, b, aux);
	else
	{
		if (aux->cost_a < 0)
			ft_do_rrx(a, aux, "rra");
		else if (aux->cost_a > 0)
			ft_do_rx(a, aux, "ra");
		if (aux->cost_b < 0)
			ft_do_rrx(b, aux, "rrb");
		else if (aux->cost_b > 0)
			ft_do_rx(b, aux, "rb");
	}
}
