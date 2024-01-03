#include "setMysql.h"
#include <stdio.h>

void setMysql() {
    MYSQL mysql;
    mysql_init(&mysql);
    const char *unix = NULL;

    if (mysql_real_connect(&mysql, "localhost", "root", "WYS666@six", "vocabulary", 3306, unix, 0)) {
        printf("successed");
    } else {
        printf("failed");
    }
}