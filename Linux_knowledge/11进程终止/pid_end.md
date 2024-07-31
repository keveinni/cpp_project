# 进程终止
## 进程终止方式
1. mian()函数return
2. 任意函数中调用exit()函数
3. abort()函数
4. 任意函数中调用_exit()、_Exit()函数
5. kill()函数
6. signal()函数接受到信号
7. raise()函数
8. pthread_exit()函数

## 进程终止处理
```c++
void exit(int status);
void _exit(int status);
void _Exit(int status);
```

1. exit()函数会调用全局变量的析构函数
2. return()函数会调用全局变量和局部变量的析构函数
3. _exit()\_Exit()函数不做清理工作

除return函数外，其余几个函数可以在括号内指定进程终止状态。

## 进程终止函数
atexit()函数可以登记终止函数，这些函数由exit()函数调用，登记的函数按登记顺序逆序调用。
```c++
int atexit(void (*func)(void));
```

示例
···c++
#include <stdio.h>
#include <stdlib.h>

void func1(void)
{
    printf("func1\n");
}

void func2(void)
{
    printf("func2\n");
}

int main(void)
{
    atexit(func1);
    atexit(func2);
    printf("main\n");
    exit(0);
}

```bash
kevein@kevein:~/Cpp_project/Linux_knowledge/11进程终止$ ./demo
fun2
fun1
```

## 进程终止状态

```bash
$ echo $?  # 查看进程终止状态
```



