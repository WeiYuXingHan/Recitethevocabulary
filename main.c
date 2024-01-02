#include <gtk/gtk.h>
#include <time.h>
#include <wchar.h>
#include <stdlib.h>

GApplicationFlags G_APPLICATION_DEFAULT_FLAGS;

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "轻轻松松背单词");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 1000);
    gtk_widget_show(window);
}

int main(int argc, char **argv) {
    FILE *file = fopen("vocabulary.txt", "w");

    // 检查文件是否成功打开
    if (file == NULL) {
        perror("No such file");
        return 1;
    }

    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);



    status = g_application_run(G_APPLICATION(app), argc, argv);
    //释放对 app 所指向的 GtkApplication 对象的引用
    g_object_unref(app);

    return status;
}