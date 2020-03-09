#include "../includes/rt.h"
#include "../includes/ui.h"

void	menu_text(t_env *v)
{
	char	*scene;
	char	*camera[3];
	char	*ori[3];
	char	*dir[3];

	scene = my_strcat("scene :  ./",v->file);
	
	ori[0] = ft_ftoa(v->cam.ori.x, 3);
	ori[1] = ft_ftoa(v->cam.ori.y, 3);
	ori[2] = ft_ftoa(v->cam.ori.z, 3);
	camera[0] = my_strcat("X:  ", ori[0]);
	camera[1] = my_strcat("Y:  ", ori[1]);
	camera[2] = my_strcat("Z:  ", ori[2]);
	put_text(v, write_text_menu2(scene, 18), 30, 22);
	put_text(v, write_text_menu2(camera[0], 20), 150, 70);
	put_text(v, write_text_menu2(camera[1], 20), 150, 105);
	put_text(v, write_text_menu2(camera[2], 20), 150, 140);
	free(camera[0]);
	free(camera[1]);
	free(camera[2]);

	dir[0] = ft_ftoa(v->cam.angle_x, 3);
	dir[1] = ft_ftoa(v->cam.angle_y, 3);
	dir[2] = ft_ftoa(v->cam.dir.z, 3);
	camera[0] = my_strcat("X:  ", dir[0]);
	camera[1] = my_strcat("Y:  ", dir[1]);
	camera[2] = my_strcat("Z:  ", dir[2]);
	put_text(v, write_text_menu2(camera[0], 20), 320, 70);
	put_text(v, write_text_menu2(camera[1], 20), 320, 105);
	put_text(v, write_text_menu2(camera[2], 20), 320, 140);

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

	if (v->selected_obj)
	{
		char *radius = ft_ftoa(v->selected_obj->radius, 3);
		put_text(v, write_text_menu2(radius, 20), 50, 650);
	}

}

void	base_menu(t_env *v)
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
			else if (size_y < 50 && size_y > 20 && size_x > 20 && size_x < v->ui.m_w - 20)
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			else if (size_y < 100 && size_y > 70 && size_x > 140 && size_x < v->ui.m_w - 200)
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			else if (size_y < 100 && size_y > 70 && size_x > (v->ui.m_w / 2) + 60 && size_x < v->ui.m_w - 20)
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			else if (size_y < 135 && size_y > 105 && size_x > 140 && size_x < v->ui.m_w - 200)
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			else if (size_y < 135 && size_y > 105 && size_x > (v->ui.m_w / 2) + 60 && size_x < v->ui.m_w - 20)
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			else if (size_y < 170 && size_y > 140 && size_x > 140 && size_x < v->ui.m_w - 200)
				v->ui.m_pixels[size_y * v->ui.m_w + size_x] = get_hex_menu(0, 0, 0, 255);
			else if (size_y < 170 && size_y > 140 && size_x > (v->ui.m_w / 2) + 60 && size_x < v->ui.m_w - 20)
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
	base_menu(v);

}