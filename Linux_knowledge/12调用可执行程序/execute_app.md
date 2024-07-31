# 执行可执行程序

在程序中可以通过system()和exec族函数进行调用可执行程序，底层逻辑是产生了一个shell进程,执行程序。不同的是，system()会创建一个子进程来执行程序，exec族函数会创建一个进程替换掉当前进程的所有内容，不会执行后续代码。

## system()

system()函数在Linux中是C库函数，在Windows中是C运行时库函数。在Linux中，system()函数的底层实现是fork()创建子进程，exec执行程序，wait()等待子进程结束，获取返回值。

```c
#include <stdlib.h>
int system(const char *command);
```

system()函数的参数是可执行程序的命令行字符串，返回值是子进程的退出码。

## exec族函数

常用的exec族函数有:
```c++
#include <unistd.h>
int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
//第一个参数为可执行程序的地址，第二个参数为可执行程序的名称，后面的参数为可执行程序的参数列表，最后一个参数为NULL。

int execv(const char *path, char *const argv[]);
```
不同的是，execv()函数的参数是可执行程序的地址和参数列表，参数列表是一个字符串数组。


