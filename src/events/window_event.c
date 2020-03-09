#include "../../includes/rt.h"

void		close_by_cross(t_env *v, SDL_Event e)
{
	Uint32	windowID[2];

	windowID[0] = SDL_GetWindowID(v->win);
	windowID[1] = SDL_GetWindowID(v->ui.m_win);

	if (e.window.windowID == windowID[0])
	{
		if (e.type == SDL_WINDOWEVENT_CLOSE)
			SDL_DestroyWindow(windowID[0]);
	}
}