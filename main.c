#include "libftprintf.h"
#include "stdio.h"

int main()
{
	char c = -1;
	char *s = "forty two";
	void *p = NULL;
	int d = 42;
	int i = 42;
	unsigned int u = 42;
	unsigned int x = 42;
	unsigned int X = 42;

	int res1 = ft_printf("char %c, str %s, ptr %p, dec %d, int %i, uns %u, hex %x, HEX %x, %%%%\n", c, s, p, d, i, u, x, X);
	int res2 = printf("char %c, str %s, ptr %p, dec %d, int %i, uns %u, hex %x, HEX %x, %%%%\n", c, s, p, d, i, u, x, X);
	printf("r1  %d\n", res1);
	printf("r2  %d\n", res2);
}