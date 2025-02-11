/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:00:30 by redei-ma          #+#    #+#             */
/*   Updated: 2025/02/11 12:58:03 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		ft_algoritmo(t_node **head_a, t_node **head_b);
void	ft_weight_tot(t_node **head_a, t_node **head_b, int *moves, int i);
void	ft_algo(t_node **head_a, t_node **head_b);
void	set_weights(int *moves, int *tmp_moves);

void	tidy_up(t_node **head_a);
int		ft_weight_b(t_node *head_b, int i);
int		ft_weight_a(t_node *head_a, int val_b);
int		pos_calc(t_node	*head, int num, int size);

void	sort_three(t_node **head_a);
void	make_move(int *moves, t_node **head_a, t_node **head_b);
void	move_double(int *moves, t_node **head_a, t_node **head_b);
void	move_single(int *moves, t_node **head_a, t_node **head_b);

void	ft_sa(t_node **head_a);
void	ft_sb(t_node **head_b);
void	ft_ss(t_node **head_a, t_node **head_b);

void	ft_pa(t_node **head_a, t_node **head_b);
void	ft_pb(t_node **head_a, t_node **head_b);

void	ft_ra(t_node **head_a);
void	ft_rb(t_node **head_b);
void	ft_rr(t_node **head_a, t_node **head_b);

void	ft_rra(t_node **head_a);
void	ft_rrb(t_node **head_b);
void	ft_rrr(t_node **head_a, t_node **head_b);

int		ft_minor(t_node *head);
int		check_finish(t_node *head_a, t_node *head_b);
int		ft_abs(int x);
int		ft_natoi(char *str);
int		checkduplicate(t_node *lst);

int		ft_freelst(t_node **head_a, t_node **head_b);
t_node	*ft_nlstnew(char *av);
t_node	*ft_lstcreation(char **av);
int		ft_lstsize_push(t_node *lst);

#endif
