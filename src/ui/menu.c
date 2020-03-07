#include "../includes/rt.h"
#include "../includes/ui.h"

void	menu_text(t_env *v)
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
	put_text(v, write_text_menu("TITRE", 18), 15, 10);
	put_text(v, write_text_menu2(scene, 18), 30, 60);
	put_text(v, write_text_menu2(camera[0], 18), 60, 120);
	put_text(v, write_text_menu2(camera[1], 18), 60, 140);
	put_text(v, write_text_menu2(camera[2], 18), 60, 160);
	free(camera[0]);
	free(camera[1]);
	free(camera[2]);
	dir[0] = ft_ftoa(v->cam.angle_x, 3);
	dir[1] = ft_ftoa(v->cam.angle_y, 3);
	dir[2] = ft_ftoa(v->cam.dir.z, 3);
	camera[0] = my_strcat("dir x:  ", dir[0]);
	camera[1] = my_strcat("dir y:  ", dir[1]);
	camera[2] = my_strcat("dir z:  ", dir[2]);
	put_text(v, write_text_menu2(camera[0], 18), 250, 120);
	put_text(v, write_text_menu2(camera[1], 18), 250, 140);
	put_text(v, write_text_menu2(camera[2], 18), 250, 160);
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

	size_y = -1;
	while (++size_y < v->ui.m_h)
	{
		size_x = -1;
		while (++size_x < v->ui.m_w)
		{
			if (size_y < (v->ui.m_h - 20) && size_y > 450 && size_x > 20 && size_x < v->ui.m_w - 20)
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			// else if (size_y < (v->ui.m_h - 290) && size_y > 20 && size_x > 20 && size_x < v->ui.m_w - 20)
			// 	v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			else
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(255, 255, 255, 255);
		}
	}
	menu_text(v);
}

void	menu(t_env *v)
{
	background_menu(v);
}