#include "nm.h"

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
		ft_printf("%s\n", stringtable + symtable[i].n_un.n_strx);
		i++;
	}
}