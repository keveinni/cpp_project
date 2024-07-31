# 目录和文件的更多操作

## 文件权限
Linux中文件的权限为
rwxrwxrwx
- 第一位代表文件类型，d代表目录，-代表普通文件
- 后面9位代表权限，每3位为一组，分别代表所有者、所属组、其他用户的权限
- r代表读权限，w代表写权限，x代表执行权限
- 可以使用chmod命令来修改文件权限，例如chmod 755 file.txt表示将file.txt的权限设置为rwxr-xr-x


### access() 检查文件权限

```c
#include <unistd.h>

int access(const char *pathname, int mode); 

/*
func：检查文件权限
参数：pathname为文件路径，mode为访问权限(R_OK(4), W_OK(2), X_OK(1), F_OK(0))
返回值：返回0表示有权限，返回-1表示没有权限或发生错误
*/
```
## stat() 获取文件详细信息

```c++
#include <sys/stat.h>

int stat(const char *path, struct stat *buf);
// struct stat结构体用于存放目录或文件的详细信息，如下：
struct stat
{
  dev_t st_dev;   	// 文件的设备编号。
  ino_t st_ino;   		// 文件的i-node。
  mode_t st_mode; 	// 文件的类型和存取的权限。
  nlink_t st_nlink;   	// 连到该文件的硬连接数目，刚建立的文件值为1。
  uid_t st_uid;   		// 文件所有者的用户识别码。
  gid_t st_gid;   		// 文件所有者的组识别码。
  dev_t st_rdev;  	// 若此文件为设备文件，则为其设备编号。
  off_t st_size;  		// 文件的大小，以字节计算。
  size_t st_blksize;	// I/O 文件系统的I/O 缓冲区大小。
  size_t st_blocks;  	// 占用文件区块的个数。
  time_t st_atime;  	// 文件最近一次被存取或被执行的时间，
 					// 在用mknod、 utime、read、write 与tructate 时改变。
  time_t st_mtime;  	// 文件最后一次被修改的时间，
					// 在用mknod、 utime 和write 时才会改变。
  time_t st_ctime;  	// 最近一次被更改的时间，在文件所有者、组、 权限被更改时更新。
};
```

st_mode的成员取值使用以下两个宏来判断：

```c
S_ISDIR(mode)  // 判断是否为目录
S_ISREG(mode)  // 判断是否为普通文件
```

### utime() 修改目录或文件的时间

```c++
#include <time.h>
#include <sys/types.h>

int utime(const char *filename, const struct utimbuf *times);
//func:修改目录或文件的时间
//参数：filename为文件路径，times为struct utimbuf结构体，包含文件访问时间和修改时间
//返回值：成功返回0，失败返回-1

struct utimbuf
{
  time_t actime;  // 文件访问时间
  time_t modtime; // 文件修改时间
};
```

### rename() 重命名目录或文件

```c++
#include <unistd.h>

int rename(const char *oldpath, const char *newpath);
//func:重命名目录或文件
//参数：oldpath为原文件路径，newpath为新文件路径
//返回值：成功返回0，失败返回-1
```

### remove() 删除目录或文件

```c++
#include <unistd.h>

int remove(const char *path);
//func:删除目录或文件
//参数：path为文件路径
//返回值：成功返回0，失败返回-1
```