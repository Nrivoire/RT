#include "../includes/rt.h"

void			display_stats(t_env *v)
{
	static char	*fps;
	static int	count = 0;
	char		*c_fps = ft_itoa(count);

	v->stats.current = clock();
	fps = NULL;
	if (v->stats.current - v->stats.last >= CLOCKS_PER_SEC)
	{
		v->stats.last = v->stats.current;
		fps == NULL ? fps = ft_strnew(10) : 0;
		count = v->stats.fps;
		v->stats.fps = 0;
	}
	put_text(v, write_text_menu2(" FPS:       ", 18), 10, 10);
	put_text(v, write_text_menu2(c_fps, 18), 60, 10);
	free(fps);
	free(c_fps);
}
