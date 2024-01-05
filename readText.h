#pragma once
#ifndef READTEXT_H
#define READTEXT_H
#include <gio/gio.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *word;
    char *chinese_translation;
    char *unit;
    char *grade;
    char *volume;
} WordInfo;

// 读取文件函数
void read_and_parse_file(const gchar *filename);
void display_words_by_input(GtkEntry *unit_entry, GtkEntry *grade_entry, GtkEntry *volume_entry);

#endif
