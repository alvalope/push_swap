/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:18:29 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 09:42:41 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_free_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	ft_free_list(t_num_list *a)
{
	t_num_list	*aux;

	while (a)
	{
		aux = a->next;
		free(a);
		a = aux;
	}
}

void	ft_free_instruccions(char **instruccions, int i)
{
	while (i >= 0)
	{
		free(instruccions[i]);
		i--;
	}
	free(instruccions);
}
