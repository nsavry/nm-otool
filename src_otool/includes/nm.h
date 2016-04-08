#ifndef NM_H

# define NM_H

# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_nmobj
{
	char			*name;
	long long			sect;
	unsigned long	value;
}				t_nmobj;

void	ft_nm(char *ptr);
void	ft_handle_64(char *ptr);

void	ft_print_nm(int nsyms, int symoff, int stroff, char *ptr);
void	ft_display(t_nmobj *obj);
t_nmobj	*ft_sort_obj(t_nmobj *obj);

void	ft_error(int nb);

char	looool[5];

#endif
