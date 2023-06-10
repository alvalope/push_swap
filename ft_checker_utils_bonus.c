/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:58 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 11:40:26 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int		x;
	size_t	i;

	i = 0;
	x = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			x = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	return (x);
}

int	ft_check_instruccion(char *ins)
{
	if (ft_strcmp(ins, "sa\n") == 0 || ft_strcmp(ins, "sb\n") == 0
		|| ft_strcmp(ins, "ss\n") == 0 || ft_strcmp(ins, "pa\n") == 0
		|| ft_strcmp(ins, "pb\n") == 0 || ft_strcmp(ins, "ra\n") == 0
		|| ft_strcmp(ins, "rb\n") == 0 || ft_strcmp(ins, "rr\n") == 0
		|| ft_strcmp(ins, "rra\n") == 0 || ft_strcmp(ins, "rrb\n") == 0
		|| ft_strcmp(ins, "rrr\n") == 0)
		return (1);
	else
		return (0);
}
