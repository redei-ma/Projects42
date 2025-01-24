/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:00:30 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:02 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_algoritmo(t_list **head_a, t_list **head_b);
void	ft_weight_tot(t_list **head_a, t_list **head_b, int *moves, int i);
void	ft_algo(t_list **head_a, t_list **head_b);
void	set_weights(int *moves, int *tmp_moves);

void	tidy_up(t_list **head_a);
int		ft_weight_b(t_list *head_b, int i);
int		ft_weight_a(t_list *head_a, int val_b);
int		pos_calc(t_list	*head, int num, int size);

void	ft_sa(t_list **head_a);
void	ft_sb(t_list **head_b);
void	ft_ss(t_list **head_a, t_list **head_b);

void	ft_pa(t_list **head_a, t_list **head_b);
void	ft_pb(t_list **head_a, t_list **head_b);

void	ft_ra(t_list **head_a);
void	ft_rb(t_list **head_b);
void	ft_rr(t_list **head_a, t_list **head_b);

void	ft_rra(t_list **head_a);
void	ft_rrb(t_list **head_b);
void	ft_rrr(t_list **head_a, t_list **head_b);

void	make_move(int *moves, t_list **head_a, t_list **head_b);
void	move_double(int *moves, t_list **head_a, t_list **head_b);
void	move_single(int *moves, t_list **head_a, t_list **head_b);

int		ft_minor(t_list *head);
int		check_finish(t_list *head_a, t_list *head_b);
int		ft_abs(int x);
int		ft_natoi(char *str);
int		checkduplicate(t_list *lst);

int		ft_freelst(t_list **head_a, t_list **head_b);
t_list	*ft_nlstnew(char *av);
t_list	*ft_lstcreation(char **av);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_lstsize(t_list *lst);
void	ft_lstprint(t_list *head_a, t_list *head_b);

#endif