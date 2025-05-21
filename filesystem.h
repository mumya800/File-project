#ifndef FILESYSTEM_H
#define FILESYSTEM_H

typedef struct {
    char *path;
    char *content;
} FileEntry;

typedef struct {
    FileEntry *entries;
    size_t     count;
} FileSystem;

static int find_index(const FileSystem *fs, const char *path);
int  fs_load (const char *fname, FileSystem *fs);
int  fs_insert(FileSystem *fs, const char *path);
int  fs_update(FileSystem *fs, const char *path, const char *new_content);
int  fs_delete(FileSystem *fs, const char *path);

#endif 
