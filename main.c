#include "libftprintf.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	int a = 0;

	char c = -1;
	char *s = "four_two";
	void *p = &s;
	int d = 42;
	int i = 42;
	int u = 42;
	int x = a;
	int X = a;

	// int res1 = ft_printf("char %c, str %s, ptr %p, dec %d, int %i, uns %u, hex %x, HEX %X, %%%\n", c, s, p, d, i, u, x, X);
	// int res2 = printf("char %c, str %s, ptr %p, dec %d, int %i, uns %u, hex %x, HEX %X, %%%\n", c, s, p, d, i, u, x, X);
	int res1 = ft_printf("%%%%%");
	ft_printf("\n");
	int res2 = printf("%%%%%");
	printf("\n");
	printf("r1_%d\n", res1);
	printf("r2_%d\n", res2);
}