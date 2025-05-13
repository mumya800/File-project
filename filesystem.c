#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

FILE *fp;
fp = fopen("file.txt", "w"); 

if (fp == NULL) {
    perror("Ошибка при открытии файла");
    return 1; 
}

// ... (операции с файлом)

fclose(fp); 


static int find_index(const FileSystem *fs, const char *path) {
    for (size_t i = 0; i < fs->count; ++i)
        if (strcmp(fs->entries[i].path, path) == 0)
            return (int)i;
    return -1;
}


if (remove("file.txt") == 0) {
    printf("Файл успешно удален.\n");
} else {
    perror("Ошибка при удалении файла");
}
