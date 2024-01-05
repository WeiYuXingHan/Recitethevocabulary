#include "readText.h"
// 读取文件
GPtrArray *word_list = NULL;

void read_and_parse_file(const gchar *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            // 去掉末尾换行符
            size_t len = strlen(line);
            if (line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            // 解析一行数据
            WordInfo *info = g_new(WordInfo, 1);
            sscanf(line, "%[^ ] %[^ ] %[^ ] %[^ ] %s", info->word, info->chinese_translation, info->unit, info->grade, info->volume);

            // 将解析出的数据添加到数组中
            if (!word_list) {
                word_list = g_ptr_array_new_with_free_func(g_free);
            }
            g_ptr_array_add(word_list, info);
        }
        fclose(file);
    } else {
        g_warning("Failed to open the file.");
    }
}

void display_words_by_input(GtkEntry *unit_entry, GtkEntry *grade_entry, GtkEntry *volume_entry) {
    const char *unit = gtk_entry_get_placeholder_text(GTK_ENTRY(unit_entry));
    const char *grade = gtk_entry_get_placeholder_text(GTK_ENTRY(grade_entry));
    const char *volume = gtk_entry_get_placeholder_text(GTK_ENTRY(volume_entry));

    int count = 0;
    for (guint i = 0; i < word_list->len && count < 5; i++) {
        WordInfo *info = g_ptr_array_index(word_list, i);
        if (strcmp(info->unit, unit) == 0 && strcmp(info->grade, grade) == 0 && strcmp(info->volume, volume) == 0) {
            //正则表达式匹配
            g_print("^[A-Za-z]+\n", info->word);
            g_print("^[A-Za-z]+\n", info->chinese_translation);
            g_print("^[A-Za-z]+\n", info->unit);
            g_print("^[A-Za-z]+\n", info->grade);
            g_print("^[A-Za-z]+\n", info->volume);
            count++;
        }
    }
}

// GString *read_file(const gchar *filename) {
//     GError *error = NULL;
//     GString *words = g_string_new(NULL);

//     FILE *file = fopen(filename, "r");
//     if (file == NULL){
//         fprintf(stderr, "Error: %s\n", strerror(errno));
//         return NULL;
//     }

//     char buffer[256];
//     while (fgets(buffer, sizeof(buffer), file)) {
//         g_string_append(words, buffer);
//     }
//     fclose(file);
//     return words;
// }
