#系统错误

Linux系统调用会将错误码存储在errno变量中，errno是一个全局变量，定义在<errno.h>头文件中，它是一个整型变量，用于表示函数调用失败的原因。我们可以通过打印errno的值，来显示错误原因。

## errno变量
- 需要引入头文件<errno.h>
- 整型的变量，表示错误原因的序号
- 不需要在程序中再次声明
- 需要配合strerror()函数或者perror()函数使用

## 函数调用

### perror()
- 头文件<stdio.h>
- 函数原型：void perror(const char *s);
- 函数功能：将errno的值转化为对应的错误信息，并输出到标准错误输出流
- 参数：s为提示信息，可以不传，默认为空字符串
- 返回值：无

```c++
int iret = mkdir("/home/kevein/Cpp_project/Linux_knowledge/08Linux系统错误/new_dir/", 0755);
    if (iret != 0){
        cout << "iret=" << iret <<"\nmkdir error" << endl;
        cout << "errno: " << errno << endl;
        perror("mkdir error:");
    
    }



```



### strerror()
- 头文件<cstring>
- 函数原型：char *strerror(int errnum);
- 函数功能：将errno的值转化为对应的错误信息
- 参数：errnum为errno的值
- 返回值：返回指向错误信息的字符串的指针

```c++
int  iret = mkdir("/home/kevein/Cpp_project/Linux_knowledge/08Linux系统错误/new_dir/", 0755);
    if(iret != 0){
        cout << "iret=" << iret <<"\nmkdir error" << endl;
        cout << "errno: " << errno << endl;
        cout << "strerror: " << strerror(errno) << endl;
    }
```
