/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:20:27 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/10 18:41:11 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	free(n);
	v = ft_calloc(sizeof(t_vars), 1);
	ft_get_quarters(a, &v);
	ft_push_swap(&a, &b, n_n, &v);
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
		{
			write(2, "Error\n", 6);
			free(n);
		}
		else
		{
			main2(n, n_n);
		}
	}
	return (0);
}
