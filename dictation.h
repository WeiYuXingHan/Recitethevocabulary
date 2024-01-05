#ifndef DICTATION_H
#define DICTATION_H
#include <gtk/gtk.h>

void dictation_secondary_window(GtkWidget *button, gpointer data);
void goToDictation(GtkEntry *user_entry, gpointer data);

#endif