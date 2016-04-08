#include "nm.h"

#include <stdio.h>

void	ft_print_nm(int nsyms, int symoff, int stroff, char *ptr)
{
	int				i;
	char			*stringtable;
	struct nlist_64	*symtable;
	t_nmobj			*obj;
	int				sectv;

	obj = malloc(sizeof(t_nmobj) * (nsyms + 1));
	symtable = (void * )ptr + symoff;
	stringtable = (void *)ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		obj[i].value = symtable[i].n_value;
		obj[i].name = ft_strdup(stringtable + symtable[i].n_un.n_strx);
		sectv = symtable[i].n_sect;
		if (sectv == 0)
			obj[i].sect = 'U';
		else if (sectv == 1)
		{
			if (symtable[i].n_type == 15)
				obj[i].sect = 'T';
			else
				obj[i].sect = 't';
		}
		else if (sectv == 2)
			obj[i].sect = 'A';
		else if (sectv == 9)
			obj[i].sect = 'D';
		else 
			obj[i].sect = 'S';
		// obj[i].sect = sectv;
		i++;
	}
	obj[i].name = NULL;
	obj = ft_sort_obj(obj);
	ft_display(obj);
}

void	ft_display(t_nmobj *obj)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (obj[i].name != NULL)
	{
		if (ft_strstr(obj[i].name, "adr://5614542") == 0)
		{
			if (obj[i].value == 0 && obj[i].sect != 'T'	&& obj[i].sect != 't')
				ft_printf("                ");
			else
			{
				j = 60;
				while (j >= 0)
				{
					c = (obj[i].value >> j) & 0xF;
					j-= 4;
					if (c >= 0 && c < 10)
						ft_printf("%c", c + 48);
					else		
						ft_printf("%c", c + 87);
				}
			}
			ft_printf(" %c ", (char)obj[i].sect);
			// ft_printf(" %i ", (int)obj[i].sect);
			ft_printf("%s\n", obj[i].name);
		}
		i++;
	}
}

t_nmobj	*ft_sort_obj(t_nmobj *obj)
{
	int		swap;
	int		i;
	t_nmobj	tmp;

	swap = 1;
	while (swap > 0)
	{
		swap = 0;
		i = 0;
		while (obj[i + 1].name != NULL)
		{
			if (ft_strcmp(obj[i].name, obj[i + 1].name) > 0)
			{
				tmp = obj[i];
				obj[i] = obj[i + 1];
				obj[i + 1] = tmp;
				swap++;
			}
			i++;
		}
	}
	return (obj);
}