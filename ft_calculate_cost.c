/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:14:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/07 12:39:29 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_count_list(t_num_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	return (i);
}

void	ft_calculate_cost_a(t_num_list **a, t_num_list **b, int n_n)
{
	t_num_list	*aux_a;
	t_num_list	*aux_b;
	int			i;
	int			sup;

	i = ft_count_list(*a);
	aux_b = *b;
	while (aux_b)
	{
		aux_a = *a;
		sup = n_n - 1;
		while (aux_a)
		{
			if (aux_a->ind > aux_b->ind && aux_a->ind <= sup)
			{
				sup = aux_a->ind;
				if (aux_a->pos <= (i / 2))
					aux_b->cost_a = aux_a->pos;
				else
					aux_b->cost_a = aux_a->pos - i;
			}
			aux_a = aux_a->next;
		}
		aux_b = aux_b->next;
	}
}

void	ft_calculate_cost_b(t_num_list **b)
{
	t_num_list	*aux;
	int			i;

	i = 0;
	aux = *b;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	aux = *b;
	while (aux)
	{
		if (aux->pos <= i / 2)
			aux->cost_b = aux->pos;
		else
			aux->cost_b = aux->pos - i;
		aux = aux->next;
	}
}
