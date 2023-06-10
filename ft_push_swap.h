/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:15:26 by alvalope          #+#    #+#             */
/*   Updated: 2023/06/08 14:06:50 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libftplus/libft.h"

typedef struct num_list
{
	int				nb;
	int				ind;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct num_list	*next;
}	t_num_list;

typedef struct s_vars
{
	int	min;
	int	max;
	int	med1;
	int	med2;
	int	med3;
	int	n_n;
}	t_vars;

long		ft_atoi_long(const char *str);
int			ft_find_upper(t_num_list **a, int nb);
void		ft_initialize_list(t_num_list **a, int n_n);
void		ft_update_lists(t_num_list **a, t_num_list **b, int n_n);
int			ft_take_nums(char *list, int **a_nums);

void		ft_get_quarters(t_num_list *lst, t_vars **v);
int			ft_is_ordered(t_num_list *lst);
void		ft_check_swap(t_num_list **a, t_num_list **b);
int			ft_total_cost(t_num_list *lst);
void		ft_check_ind0(t_num_list **a, int n_n);

int			ft_check_valid_num(char	*list);
int			ft_check_repeat_num(int	*a_nums, int n);
int			*ft_check_list(char *list, int *n_n);
int			ft_check_args2(char	**argv, int argc, int **a_nums);
int			*ft_check_args(char	**argv, int argc, int **a_nums, int *n_n);

t_num_list	*ft_lst_new(int content);
t_num_list	*ft_lst_before_last(t_num_list *lst);
t_num_list	*ft_lst_last(t_num_list *lst);
void		ft_lst_add_front(t_num_list **lst, int nb, int ind);
void		ft_lst_add(t_num_list **lst, int nb);

void		ft_free_nums(char **nums);
void		ft_free_list(t_num_list *a);
void		ft_free_instruccions(char **instruccions, int i);

int			ft_count_list(t_num_list *lst);
void		ft_calculate_cost_a(t_num_list **a, t_num_list **b, int n_n);
void		ft_calculate_cost_b(t_num_list **b);

void		ft_swap(t_num_list **l, char *op);
void		ft_swaps(t_num_list **a, t_num_list **b, char *op);
void		ft_push(t_num_list **l1, t_num_list **l2, char *op);

void		ft_rotate(t_num_list **l, char *op);
void		ft_rotate_both(t_num_list **a, t_num_list **b, char *op);
void		ft_reverse_rotate(t_num_list **l, char *op);
void		ft_reverse_both(t_num_list **a, t_num_list **b, char *op);

void		ft_do_rr(t_num_list **a, t_num_list **b, t_num_list *aux);
void		ft_do_r(t_num_list **a, t_num_list **b, t_num_list *aux);
void		ft_do_rrx(t_num_list **lst, t_num_list *aux, char *op);
void		ft_do_rx(t_num_list **lst, t_num_list *aux, char *op);
void		ft_do_r_and_rr(t_num_list **a, t_num_list **b, t_num_list *aux);

void		ft_b_to_a(t_num_list **a, t_num_list **b, int pos);
void		ft_ps_bigger3(t_num_list **a, t_num_list **b, t_vars **v);
void		ft_ps_bigger2(t_num_list **a, t_num_list **b, t_vars **v);
void		ft_ps_bigger(t_num_list **a, t_num_list **b, t_vars **v);
int			ft_push_swap(t_num_list **a, t_num_list **b, int n_n, t_vars **v);

void		ft_ps_3(t_num_list **a, t_num_list **b, int *ordered);
void		ft_ps_4(t_num_list **a, t_num_list **b, int *ordered);
void		ft_ps_5a(t_num_list **a, t_num_list **b, int *ordered);
void		ft_ps_5b(t_num_list **a, t_num_list **b, int *ordered);
void		ft_ps_5(t_num_list **a, t_num_list **b, int *ordered);

void		ft_execute(char *instruccion, t_num_list **a, t_num_list **b);
void		ft_checker2(t_num_list **a, t_num_list **b, char **instr, int n);
void		ft_checker(t_num_list **a, t_num_list **b);
void		main2(int *n, int n_n);
int			main(int argc, char *argv[]);

void		ft_swap_chk(t_num_list **l);
void		ft_swaps_chk(t_num_list **a, t_num_list **b);
void		ft_push_chk(t_num_list **l1, t_num_list **l2);

void		ft_rotate_chk(t_num_list **l);
void		ft_rotate_both_chk(t_num_list **a, t_num_list **b);
void		ft_reverse_rotate_chk(t_num_list **l);
void		ft_reverse_both_chk(t_num_list **a, t_num_list **b);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_check_instruccion(char *ins);

#endif