#include "nm.h"

int		lol;
char	*lool = NULL;
char	loool[] = "bonswag";

int		main(int ac, char **av)
{
	int				fd;
	char			*ptr;
	struct stat		buf;
	int				i;

	if (ac < 2)
	{
		ft_error(0);
		return (-1);
	}
	i = 1;
	while (i < ac)
	{
		if (ac > 2)
			ft_printf("%s:\n", av[i]);
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_error(1);
			return (-1);
		}
		if (fstat(fd, &buf) < 0)
		{
			ft_error(2);
			return (-1);
		}
		if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		{
			ft_error(3);
			return (-1);
		}
		ft_nm(ptr);
		if (munmap(ptr, buf.st_size) < 0)
		{
			ft_error(4);
			return (-1);
		}
		i++;
	}
	return (0);
}
