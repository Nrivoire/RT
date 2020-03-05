#ifndef UI_H
# define UI_H

# include "gtk/gtk.h"

typedef struct		s_ui
{
	GtkWidget		*window;
	GtkWidget		*main_box;
	GtkWidget		*progress_bar;
}					t_ui;

#endif
