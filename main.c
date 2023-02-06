#include "ft_printf.h"

int		main()
{
	int		nb;
	int		nb1;
	int		nb2;

	nb2 = 200;
	nb1 = 150;
	nb = 120;
	ft_printf("bonjour%5dhello%dsalut%5i", nb, nb1, nb2);
	return (0) ;
}