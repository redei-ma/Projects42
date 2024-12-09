#include "ft_printf.h"

/* int main ()
{
	printf("t; ciao6%  t");
	printf("\n");
	printf("j; ciao6%  j");
	printf("\n");
	printf("t; ciao6%t");
	printf("\n");
	printf("l; ciao6%l");
	printf("\n");
	printf("t; ciao6%t:=");
	printf("\n");
	printf("j; ciao6%j:=");
	printf("\n");
	// printf("tj; ciao6%t:j");
	// printf("\n");
	printf("t; ciao6%}t");
	printf("\n");
	printf("j; ciao6%}j");
	printf("\n");
	printf("t; ciao6%tl");
	printf("\n");
	printf("j; ciao6%jl");
	printf("\n");
	printf("t; ciao6%t:r");
	printf("\n");
	printf("j; ciao6%j:r");
	printf("\n");
	printf("i; ciao6%i:r", 750);
	printf("\n");
	printf("\n");
	printf("%%; ciao6%%:r");
	printf("\n");
	printf("%%; ciao6%%jl");
	// ft_printf();
} */


int main() 
{
    int x = 42;
    int *ptr = &x;

    int d = printf("Indirizzo del puntatore con printf originale: %p\n", ptr);
    int m = ft_printf("Indirizzo del puntatore con ft_printf: %p\n", ptr);

	printf("\n%d\n%d", d, m);
    return 0;
}
