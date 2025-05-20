#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

// просмотр файла внутри файловой системы
static int find_index(const FileSystem *fs, const char *path) {
    for (size_t i = 0; i < fs->count; ++i)
        if (strcmp(fs->entries[i].path, path) == 0)
            return (int)i;
    return -1;
}

// открытие файла
int fs_load(const char *fname, FileSystem *fs) {
    FILE *f = fopen(fname, "r");
    if (!f) {                        
        fs->entries = NULL;
        fs->count = 0;
        return 0;
    }

// удаление файла из файловой системы
int fs_delete(FileSystem *fs, const char *path) {
    int idx = find_index(fs, path);
    if (idx < 0) return -1;
    free(fs->entries[idx].path);
    free(fs->entries[idx].content);
    memmove(&fs->entries[idx], &fs->entries[idx + 1],
            (fs->count - idx - 1) * sizeof(FileEntry));
    fs->count--;
    return 0;
}
