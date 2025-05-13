0907-31  
:guardsman: Сакаева Диана  
:smiley_cat: Загидуллина Камила  
:ok_woman: Шамуранова Елизавета  
  

## 1. Функция открытия или создания файла
  
```
`FILE *open_or_create_file(const char *filename) {    
     FILE *file = fopen(filename, "a+");    
     if (file == NULL) {    
         perror("Ошибка при открытии файла");    
         return NULL;    
     }    
     return file;    
}`  
```  

## 2. Функция для поиска индекса файла в файловой системе
  
```
`static int find_index(const FileSystem *fs, const char *path) {  
    for (size_t i = 0; i < fs->count; ++i) {  
        if (strcmp(fs->entries[i].path, path) == 0) {  
            return (int)i;  
        }  
    }  
    return -1;   
}`  
```
  

## 3. Код для удаления файла

```
`if (remove("file.txt") == 0) {  
    printf("Файл успешно удален.\n");  
} else {  
    perror("Ошибка при удалении файла");  
}`  
```
