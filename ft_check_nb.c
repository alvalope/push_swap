/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:56:49 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 13:55:45 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_valid_num(char	*list)
{
	int	i;

	i = 0;
	while (list && list[i])
	{
		if (list[i] == '-')
		{
			if (!list[i + 1] || (list[i - 1] && list[i - 1] != ' '))
				return (0);
			else if (list[i + 1] >= '0' && list[i + 1] <= '9')
				i++;
			else
				return (0);
		}
		else if (list[i] == ' ' || (list[i] >= '0' && list[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_repeat_num(int	*a_nums, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (a_nums[i] == a_nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_check_list(char *list, int *n_n)
{
	int		*a_nums;

	if (list)
	{
		if (ft_check_valid_num(list))
		{
			*n_n = ft_take_nums(list, &a_nums);
			if (*n_n)
			{
				if (ft_check_repeat_num(a_nums, *n_n))
					return (a_nums);
			}
		}
	}
	return (0);
}

int	ft_check_args2(char	**argv, int argc, int **a_nums)
{
	int	i;
	int	nul;

	i = 1;
	while (i < argc)
	{
		if (ft_check_valid_num(argv[i]))
		{
			nul = ft_strncmp(argv[i], "", 1);
			if (nul && ft_atoi(argv[i]) == ft_atoi_long(argv[i]))
				(*a_nums)[i - 1] = ft_atoi(argv[i]);
			else
			{
				free(*a_nums);
				return (0);
			}
		}
		else
		{
			free(*a_nums);
			return (0);
		}
		i++;
	}
	return (1);
}

int	*ft_check_args(char	**argv, int argc, int **a_nums, int *n_n)
{
	*a_nums = ft_calloc(argc, sizeof(int));
	*n_n = argc - 1;
	if (!ft_check_args2(argv, argc, a_nums))
		return (0);
	if (ft_check_repeat_num(*a_nums, *n_n))
		return (*a_nums);
	else
	{
		free(*a_nums);
		return (0);
	}
}
