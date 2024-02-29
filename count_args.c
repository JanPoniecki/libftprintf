int	count_args(const char *s)
{
	int	n;
	int	mode;

	mode = -1;
	n = 0;
	while (*s)
	{
		if (*s == '%' && mode == -1)
			mode *= -1;
		else if (mode == 1)
		{
			n++;
			mode *= -1;
		}
		s++;
	}
	return (n);
}
