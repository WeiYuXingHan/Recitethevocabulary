#include <gio/gio.h>
#include <gtk/gtk.h>
#include <mysql.h>
#include "review.h"
#include "recite.h"
#include "dictation.h"
#include "readText.h"
#include <stdlib.h>

GtkWidget *window; //主窗口


void quit_out(GtkButton *button, gpointer user_data) {
    //用于退出程序的回调函数
    GtkWindow *window = GTK_WINDOW (user_data);
    gtk_window_destroy(window);
}

static void app_activate(GtkApplication *app, gpointer user_data) {
    GtkBox *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 150);
    //创建窗口实例
    window = gtk_application_window_new(app);
    //设置窗口标题大小
    gtk_window_set_title(GTK_WINDOW(window), "轻轻松松背单词-首页");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 1000);
    //添加按钮
    GtkButton *toRecite = gtk_button_new_with_label("开始背诵单词");
    GtkButton *toDictation = gtk_button_new_with_label("开始默写单词");
    GtkButton *toReview = gtk_button_new_with_label("开始复习单词");
    GtkButton *quit = gtk_button_new_with_label("退出");
    //设置按钮大小
    gtk_widget_set_size_request(toRecite, 50, 50);
    gtk_widget_set_size_request(toDictation, 50, 50);
    gtk_widget_set_size_request(toReview, 50, 50);
    gtk_widget_set_size_request(quit, 50, 50);
    //设置按钮回调
    g_signal_connect(toRecite, "clicked", G_CALLBACK(goToRecite), NULL);
    g_signal_connect(toDictation, "clicked", G_CALLBACK(goToDictation), NULL);
    g_signal_connect(toReview, "clicked", G_CALLBACK(goToReview), NULL);
    g_signal_connect (quit, "clicked", G_CALLBACK(quit_out), window);
    //添加主页面label
    GtkWidget *label = gtk_label_new(
            "欢迎使用【轻轻松松背    单词】，该项目使用GTK4进行开发。点击【开始背单词】按钮开始使用，点击【退出】按钮退出程序");
    gtk_widget_set_size_request(label, 80, 150);
    //添加box子控件
    gtk_box_append(box, label);
    gtk_box_append(box, toRecite);
    gtk_box_append(box, toDictation);
    gtk_box_append(box, toReview);
    gtk_box_append(box, quit);
    gtk_widget_show(box);
    //展示窗口
    gtk_window_set_child(GTK_WINDOW(window), box);
    gtk_widget_show(window);
}

int main(int argc, char *argv[]) {
    int stat;
    GtkCssProvider *provider = gtk_css_provider_new();
    GtkApplication *app; // 应用程序

    read_and_parse_file("vocabulary.txt");
    app = gtk_application_new("com.github.ToshioCP.tfv1", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(app_activate), NULL);
    stat = g_application_run(G_APPLICATION (app), argc, argv); //运行程序
    g_object_unref(app); //释放资源

    return stat;
}


