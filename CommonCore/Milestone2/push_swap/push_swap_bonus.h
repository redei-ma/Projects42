/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:48 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/28 16:57:47 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int		custom_move(t_node **head_a, t_node **head_b, char *line, int *check);
void	write_finish(t_node *head_a, t_node *head_b);

int		ft_swap(t_node **head);
int		ft_swap_double(t_node **head_a, t_node **head_b);
int		ft_push_a(t_node **head_a, t_node **head_b);
int		ft_push_b(t_node **head_a, t_node **head_b);

int		ft_rotate(t_node **head);
int		ft_rotate_double(t_node **head_a, t_node **head_b);
int		ft_rrotate(t_node **head);
int		ft_rrotate_double(t_node **head_a, t_node **head_b);

#endif
