/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:22:16 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 14:02:46 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ft_atoi_long(const char *str)
{
	int		i;
	long	sum;
	int		neg;

	i = 0;
	neg = 1;
	sum = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - 48);
		i++;
	}
	return (sum * neg);
}

int	ft_find_upper(t_num_list **a, int nb)
{
	t_num_list	*aux;
	int			i;

	i = 0;
	aux = *a;
	while (aux)
	{
		if (aux->nb > nb)
			i++;
		aux = aux->next;
	}
	return (i);
}

void	ft_initialize_list(t_num_list **a, int n_n)
{
	t_num_list	*aux;

	aux = *a;
	while (aux)
	{
		aux->ind = n_n - 1 - ft_find_upper(a, aux->nb);
		aux = aux->next;
	}
}

void	ft_update_lists(t_num_list **a, t_num_list **b, int n_n)
{
	t_num_list	*aux_a;
	t_num_list	*aux_b;
	int			i;

	i = 0;
	aux_a = *a;
	aux_b = *b;
	while (aux_a)
	{
		aux_a->pos = i;
		i++;
		aux_a = aux_a->next;
	}
	i = 0;
	while (aux_b)
	{
		aux_b->pos = i;
		i++;
		aux_b = aux_b->next;
	}
	ft_calculate_cost_b(b);
	ft_calculate_cost_a(a, b, n_n);
}

int	ft_take_nums(char *list, int **a_nums)
{
	int		i;
	char	**nums;

	nums = ft_split(list, ' ');
	if (!nums)
		return (0);
	i = 0;
	while (nums[i])
		i++;
	*a_nums = ft_calloc(i, sizeof(int));
	i = 0;
	while (nums[i])
	{
		if (ft_atoi(nums[i]) == ft_atoi_long(nums[i]))
			(*a_nums)[i] = ft_atoi(nums[i]);
		else
			return (ft_free_nums(nums), 0);
		i++;
	}
	ft_free_nums(nums);
	return (i);
}
