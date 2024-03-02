#include "libftprintf.h"
#include "stdio.h"

int main()
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

	int res1 = ft_printf("char %c, str %s, ptr %p, dec %d, int %i, uns %u, hex %x, HEX %X, %%%%\n", c, s, p, d, i, u, x, X);
	int res2 = printf("char %c, str %s, ptr %p, dec %d, int %i, uns %u, hex %x, HEX %X, %%%%\n", c, s, p, d, i, u, x, X);
	printf("r1  %d\n", res1);
	printf("r2  %d\n", res2);
}