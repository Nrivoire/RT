#include "../includes/rt.h"

void	free_parsing_list(t_env *v)
{
	free(v->ob);
	free(v->lg);
}
