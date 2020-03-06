#include "../includes/rt.h"
#include "../includes/ui.h"

void	menu_text(t_env *v, int x)
{
	char	*scene;
	char	*camera[3];
	char	*ori[3];
	char	*dir[3];

	scene = my_strcat("scene:  ./",v->file);
	ori[0] = ft_ftoa(v->cam.ori.x, 3);
	ori[1] = ft_ftoa(v->cam.ori.y, 3);
	ori[2] = ft_ftoa(v->cam.ori.z, 3);
	camera[0] = my_strcat("pos x:  ", ori[0]);
	camera[1] = my_strcat("pos y:  ", ori[1]);
	camera[2] = my_strcat("pos z:  ", ori[2]);
	put_text(v, write_text_menu("MENU", 18), x + 5, 10);
	put_text(v, write_text_menu2(scene, 18), x + 10, 60);
	put_text(v, write_text_menu2(camera[0], 18), x + 30, 120);
	put_text(v, write_text_menu2(camera[1], 18), x + 30, 140);
	put_text(v, write_text_menu2(camera[2], 18), x + 30, 160);
	free(camera[0]);
	free(camera[1]);
	free(camera[2]);
	dir[0] = ft_ftoa(v->cam.angle_x, 3);
	dir[1] = ft_ftoa(v->cam.angle_y, 3);
	dir[2] = ft_ftoa(v->cam.dir.z, 3);
	camera[0] = my_strcat("dir x:  ", dir[0]);
	camera[1] = my_strcat("dir y:  ", dir[1]);
	camera[2] = my_strcat("dir z:  ", dir[2]);
	put_text(v, write_text_menu2(camera[0], 18), x + 200, 120);
	put_text(v, write_text_menu2(camera[1], 18), x + 200, 140);
	put_text(v, write_text_menu2(camera[2], 18), x + 200, 160);
	free(scene);
	free(camera[0]);
	free(camera[1]);
	free(camera[2]);
	free(ori[0]);
	free(ori[1]);
	free(ori[2]);
	free(dir[0]);
	free(dir[1]);
	free(dir[2]);
}

void	background_menu(t_env *v)
{
	int		size_x;
	int		size_y;
	int		cx;

	cx = v->w - (v->w / 3);
	size_y = 5;
	while (++size_y < v->h - 5)
	{
		size_x = v->w - (v->w / 3);
		while (++size_x < v->w - 5)
		{
			if (size_y < (v->h - 20) && size_y > (v->h - (v->h / 3)) && size_x > cx + 20 && size_x < v->w - 20)
				v->pixels[size_y * v->w + size_x] = get_hex_menu(0, 0, 0, 255);
			else
				v->pixels[size_y * v->w + size_x] = get_hex_menu(255, 255, 255, 255);
		}
	}
	menu_text(v, cx);
}

void	menu(t_env *v)
{
	background_menu(v);
}