#include "nm.h"

#include <stdio.h>

void	ft_print_nm(int nsyms, int symoff, int stroff, char *ptr)
{
	int				i;
	char			*stringtable;
	struct nlist_64	*symtable;

	symtable = (void * )ptr + symoff;
	stringtable = (void *)ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		unsigned int	maj = (symtable[i].n_value >> 32);
		unsigned int	min = symtable[i].n_value;
		int				sect = symtable[i].n_sect;
		if (maj == 0 && min == 0)
			printf("                 ");
		else
			printf("%08x%08x ", maj, min);
		if (sect == 0)
			printf("U ");
		else if (sect == 1)
			printf("T ");
		else
			printf("L");
		printf("%s\n", stringtable + symtable[i].n_un.n_strx);
		i++;
	}
}