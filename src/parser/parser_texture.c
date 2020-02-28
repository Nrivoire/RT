
#include "../includes/rt.h"

static void		read_texture(t_env *v, t_file *file)
{
	char		*tmp;
	int			i;

	i = 0;
	while (read_line(file) > 0)
	{
		tmp = ft_strdup(file->line);
		
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}

int				parser_texture(t_env *v)
{
	t_file	file;

	(file.fd = open("WOOD.xpm", O_RDWR)) == -1 ? ft_error("Error: texture 'WOOD.xpm' introuvable") : 0;
	read_texture(v, &file);
	close(file.fd) == -1 ? ft_error("Can't close fd") : 0;
	ft_strdel(&file.line);
	return (0);
}

/**/

void			init_texture(t_env *v)
{
	v->p.tex.check = IMG_Load("../textures/checkboard_test.jpg");
	//v->p.tex.wood = SDL_LoadBMP("../textures/wood.bmp");
	v->p.tex.brick = IMG_Load("../textures/brick.jpg");
	
}
