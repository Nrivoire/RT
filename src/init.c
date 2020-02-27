#include "../includes/rt.h"

void			init_value(t_env *v)
{
	v->w = 1280;
	v->h = 720;
	v->cam.fov = 60;
	v->selected_obj = NULL;
	// init list du parser pour le malloc
	v->p.ob = NULL;
	v->p.lg = NULL;
}

void			scene_value(t_env *v)
{
	v->cam.ori = v->p.cam.pos;
	v->cam.dir = v->p.cam.dir;
}

void			restart_values(t_env *v)
{
	init_value(v);
	scene_value(v);
}