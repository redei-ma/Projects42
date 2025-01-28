/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:07:01 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/28 16:01:51 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
size_t	ft_putstr(char *s);
int		ft_putnbr(long long n);
int		ft_puthex(long long n, char c);
int		ft_putptr(unsigned long long n);
int		ft_printf(const char *format, ...);

#endif
