#include <gtk/gtk.h>
#include <mysql.h>
#include <time.h>
#include <wchar.h>
#include <stdlib.h>
#include "setIcon.h"

#define DEF 12

//处理点击按钮之后的回调函数
static void click1_cb(GtkButton *btn, gpointer user_data) {
    const gchar *s;
    s = gtk_button_get_label(btn);
    if (g_strcmp0(s, "Hello.") == 0)
        gtk_button_set_label(btn, "Good-bye.");
    else
        gtk_button_set_label(btn, "Hello.");
}

static void click2_cb(GtkButton *btn, gpointer user_data) {
    GtkWindow *win = GTK_WINDOW (user_data);
    gtk_window_destroy(win);
}

static void app_activate(GApplication *app, gpointer *user_data) {
    GtkWidget *win;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *btn1;
    GtkWidget *btn2;


    win = gtk_application_window_new(GTK_APPLICATION (app));
    gtk_window_set_title(GTK_WINDOW (win), "lb4");
    gtk_window_set_default_size(GTK_WINDOW (win), 1000, 1000);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    label = gtk_label_new("欢迎使用【轻轻松松背单词】，该项目使用GTK4进行开发。点击【开始背单词】按钮开始使用，点击【退出】按钮退出程序");

    gtk_box_set_homogeneous(GTK_BOX (box), TRUE);
    gtk_window_set_child(GTK_WINDOW (win), box);

    btn1 = gtk_button_new_with_label("开始背单词.");
    g_signal_connect (btn1, "clicked", G_CALLBACK(click1_cb), NULL);

    btn2 = gtk_button_new_with_label("退出");
    g_signal_connect (btn2, "clicked", G_CALLBACK(click2_cb), win);

    gtk_box_append(GTK_BOX (box), label);
    gtk_box_append(GTK_BOX (box), btn1);
    gtk_box_append(GTK_BOX (box), btn2);

    gtk_widget_show(win);
}


int main(int argc, char **argv) {

    //打开单词库txt文件
    FILE *file = fopen("vocabulary.txt", "r+");
    // 检查文件是否成功打开
    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    GtkApplication *app;
    int stat;

    app = gtk_application_new("com.github.ToshioCP.pr2", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(app_activate), NULL);
    stat = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    fclose(file);
    return stat;
}