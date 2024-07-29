# 文件目录操作

## 目录操作

### 获取当前工作目录

```c++
#include <unistd.h>
getcwd(char *buf, size_t size);
```

```c++
#include <unistd.h>
#include <cstdlib>
char *path2 = get_current_dir_name(void);
free(path2);
```
**注意动态分配的内存需要使用free()释放**

### 创建目录

```c++
#include <sys/stat.h>  //mkdir()头文件
#include <sys/types.h>
int mkdir(const char *path, mode_t mode)； //mode表示用户权限,返回值为0表示成功，其他表示失败
```

### 改变当前工作目录
```c++
#include <unistd.h>
int chdir(const char *path)；  //返回值为0表示成功，返回值为1表示失败
```

### 删除目录
```c++
#include <unistd.h>
int rmdir(const char *path); //返回值为0表示成功，返回值为1表示失败
```

## 目录列表操作

```
#include <dirent.h>

DIR *opendir(const char *name); //返回一个指向DIR结构体的指针
struct dirent *readdir(DIR *dirp); //返回一个指向dirent结构体的指针
int closedir(DIR *dirp); //关闭目录流
```


