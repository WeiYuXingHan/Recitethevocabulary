#include "review.h"
//复习单词
void goToReview(GtkEntry *user_entry, gpointer data) {
    //用于创建二级页面的回调函数
    review_secondary_window(user_entry, data);
}
void review_secondary_window(GtkWidget *button, gpointer data) {
    GtkWidget *secondary_window;
    GtkWidget *box;
    GtkWidget *label;
    GtkEntry *entry;
    GtkWidget *start;

    secondary_window = gtk_window_new();
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 50);
    label = gtk_label_new("输入你的年级(7/8/9)、上下册(上/下)、单元(1/2/3/4)");
    entry = gtk_entry_new();
    start = gtk_button_new_with_label("获取输入");
    gtk_widget_set_size_request(start, 50, 50);
    gtk_widget_set_size_request(entry, 50, 50);

    gtk_window_set_title(GTK_WINDOW(secondary_window), "复习单词");
    gtk_window_set_default_size(GTK_WINDOW(secondary_window), 1000, 1000);


//    GtkEntryBuffer *buffer = gtk_entry_buffer_new("123",3);
//    gtk_entry_buffer_set_text(buffer, "123", -1);

    gtk_box_append(box,label);
    gtk_box_append(box,entry);
    gtk_box_append(box,start);

    gtk_window_set_child(GTK_WINDOW(secondary_window),box);
    gtk_widget_show(secondary_window);
}