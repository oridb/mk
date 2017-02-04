#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

#include "hello.h"

static void
hello(GtkWidget *widget, gpointer data)
{
	printf("Hello World\n");
}

static gboolean
delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	return FALSE;
}

/* Another callback */
static void
destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

void
hello_showgtk(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *button;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

	button = gtk_button_new_with_label("Hello World");
	g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);

	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show(button);
	gtk_widget_show(window);

	gtk_main();
}
