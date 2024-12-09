#ifndef FT_PRINTF_H
 # define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
size_t	ft_putstr(char *s);
int		ft_putnbr(long long n);
int		ft_puthex(long long n, char c);
int		ft_putptr(unsigned long long n);
int		ft_printf(const char *format, ...);

#endif