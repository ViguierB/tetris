/*
** test.c for test in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Mar  7 11:06:02 2017 augustin leconte
** Last update Tue Mar  7 11:17:35 2017 augustin leconte
*/
#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{
    GtkWidget* Fenetre = NULL;
    GtkWidget* Label = NULL;
    gchar* TexteConverti = NULL;

    gtk_init(&argc, &argv);

    Fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Fenetre), "C'est Mieux que la Ncurses");
    gtk_window_set_default_size(GTK_WINDOW(Fenetre), 300, 100);

    TexteConverti = g_locale_to_utf8("<span face=\"Verdana\" foreground="
    "\"#73b5ff\" size=\"xx-large\"><b>Hein</b></span>\n <span face=\"Verdana\""
    " foreground=\"#39b500\" size=\"x-large\">Vous avez dit GTK ?</span>\n", -1,
    NULL, NULL, NULL);
    Label=gtk_label_new(TexteConverti);
    g_free(TexteConverti);
    gtk_label_set_use_markup(GTK_LABEL(Label), TRUE);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);
    gtk_container_add(GTK_CONTAINER(Fenetre), Label);
    gtk_widget_show_all(Fenetre);
    g_signal_connect(G_OBJECT(Fenetre), "delete-event",
    G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
    return EXIT_SUCCESS;
}
