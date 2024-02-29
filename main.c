#include "libftprintf.h"

int main(int argv, char **argc)
{
	int a = 1;
	char b = '2';
	char *c = "trzy";
	ft_printf(argc[1], a, b, c);
	printf("\n");
}