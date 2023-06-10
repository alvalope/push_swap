/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:20:31 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 14:07:12 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_execute(char *instruccion, t_num_list **a, t_num_list **b)
{
	if (ft_strcmp(instruccion, "sa\n") == 0)
		ft_swap_chk(a);
	else if (ft_strcmp(instruccion, "sb\n") == 0)
		ft_swap_chk(b);
	else if (ft_strcmp(instruccion, "ss\n") == 0)
		ft_swaps_chk(a, b);
	else if (ft_strcmp(instruccion, "pa\n") == 0)
		ft_push_chk(b, a);
	else if (ft_strcmp(instruccion, "pb\n") == 0)
		ft_push_chk(a, b);
	else if (ft_strcmp(instruccion, "ra\n") == 0)
		ft_rotate_chk(a);
	else if (ft_strcmp(instruccion, "rb\n") == 0)
		ft_rotate_chk(b);
	else if (ft_strcmp(instruccion, "rr\n") == 0)
		ft_rotate_both_chk(a, b);
	else if (ft_strcmp(instruccion, "rra\n") == 0)
		ft_reverse_rotate_chk(a);
	else if (ft_strcmp(instruccion, "rrb\n") == 0)
		ft_reverse_rotate_chk(b);
	else if (ft_strcmp(instruccion, "rrr\n") == 0)
		ft_reverse_both_chk(a, b);
}

void	ft_checker2(t_num_list **a, t_num_list **b, char **instr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_execute(instr[i], a, b);
		i++;
	}
	if (ft_is_ordered(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_instruccions(instr, i - 1);
}

void	ft_checker(t_num_list **a, t_num_list **b)
{
	char	**instruccions;
	int		i;
	int		n_ins;

	i = 0;
	instruccions = ft_calloc(10000 * sizeof(char *), 1);
	instruccions[i] = ft_get_next_line(0);
	while (instruccions[i])
		instruccions[++i] = ft_get_next_line(0);
	n_ins = i;
	i = 0;
	while (i < n_ins)
	{
		if (!ft_check_instruccion(instruccions[i]))
			break ;
		i++;
	}
	if (i != n_ins)
	{
		ft_free_instruccions(instruccions, n_ins - 1);
		write(2, "Error\n", 6);
		return ;
	}
	ft_checker2(a, b, instruccions, n_ins);
}

void	main2(int *n, int n_n)
{
	int			i;
	t_num_list	*a;
	t_num_list	*b;
	t_vars		*v;

	i = 0;
	b = 0;
	a = ft_lst_new(n[i]);
	while (++i < n_n)
		ft_lst_add(&a, n[i]);
	v = ft_calloc(sizeof(t_vars), 1);
	ft_checker(&a, &b);
	ft_free_list(a);
	free(v);
}

int	main(int argc, char *argv[])
{
	int			*n;
	int			n_n;

	if (argc >= 2)
	{
		if (argc == 2)
			n = ft_check_list(argv[1], &n_n);
		else
			n = ft_check_args(argv, argc, &n, &n_n);
		if (!n)
			write(2, "Error\n", 6);
		else
		{
			main2(n, n_n);
			free(n);
		}
	}
	return (0);
}
