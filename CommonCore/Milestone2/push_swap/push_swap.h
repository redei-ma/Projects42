#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct slist
{
	int			number;
	struct s_list *nest;
}	t_list;

#endif