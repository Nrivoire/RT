#include "../includes/rt.h"

int		add_lst_obj(t_object **ob, t_object content)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (0);
	new->type = content.type;
	new->radius = content.radius;
	new->pos = content.pos;
	new->dir = content.dir;
	new->a = content.a;
	new->b = content.b;
	new->c = content.c;
	new->color = content.color;
	new->reflect = content.reflect;
	new->refract = content.refract;
	new->transparency = content.transparency;
	new->absorbtion = content.absorbtion;
	new->ambient = content.ambient;
	new->diffuse = content.diffuse;
	new->specular = content.specular;
	new->shininess = content.shininess;
	new->texture = content.texture;
	new->next = (!*ob) ? NULL : *ob;
	*ob = new;
	return (0);
}

int		add_lst_lgt(t_light **lg, t_light content)
{
	t_light		*new;

	if (!(new = malloc(sizeof(t_light))))
		return (0);
	new->type = content.type;
	new->pos = content.pos;
	new->dir = content.dir;
	// autres variables ?
	new->next = (!*lg) ? NULL : *lg;
	*lg = new;
	return (0);
}
