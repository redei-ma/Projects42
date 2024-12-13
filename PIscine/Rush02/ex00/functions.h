/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:21:17 by anacotti          #+#    #+#             */
/*   Updated: 2024/11/03 20:32:42 by anacotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H



int		str_len(char *str);
int		file_dimension(void);
char	*put_dictionary(void);
void	drop(char *dct);
void	search_one(char *dct, char *temp_arr, int pos);
int		search_multi(char *dct, char *temp_arr);
void	hundreds(char *dct, char *temp_arr);
void	tens(char *dct, char *temp_arr);
int		traffic_light(char *dct, char temp_arr[]);
void	build_ntc(char *dct, char *argv);

#endif
