#ifndef NM_H

# define NM_H

# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "libft.h"

void	ft_nm(char *ptr);
void	ft_handle_64(char *ptr);

void	ft_print_nm(int nsyms, int symoff, int stroff, char *ptr);

void	ft_error(int nb);

#endif
