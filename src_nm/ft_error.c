#include "nm.h"

void	ft_error(int nb)
{
	ft_printf("Error: ");
	if (nb == 0)
		ft_printf("arg");
	if (nb == 1)
		ft_printf("open");
	if (nb == 2)
		ft_printf("stat");
	if (nb == 3)
		ft_printf("mmap");
	if (nb == 4)
		ft_printf("munmmap");
}