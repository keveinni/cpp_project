# gdb调试core文件

*核心文件（core file）是在程序异常终止（比如由于段错误或者非法指令等）时系统自动生成的一种文件。它包含了在程序崩溃时内存中的完整镜像，通常包括程序的数据、堆栈和寄存器状态等信息。*

## 查看gdb的core参数

在终端中使用命令行进行查看。
```
unlimit -a //查看系统的资源限制,core=0表示生成core文件

unlimit -c unlimited //将核心文件设置为无穷大，即取消大小限制，确保程序错误时能产生核心文件。
```

## 调试实例

```
// 第一次调试

kevein@kevein:~/Cpp_project/Linux_knowledge/04gdb调试core文件$ g++ -o demo demo.cpp -g
kevein@kevein:~/Cpp_project/Linux_knowledge/04gdb调试core文件$ gdb demo
...
(gdb) r
...
Program received signal SIGSEGV, Segmentation fault.  //表示调试到了问题行，发生了段错误
0x0000555555555304 in bb (bh=3, xm="冰冰") at demo.cpp:8
8         *ptr=3;
(gdb) c
Continuing 
Program terminated with signal SIGSEGV, Segmentation fault.  //程序异常退出
The program no longer exists.
```

```
// 第二次调试
kevein@kevein:~/Cpp_project/Linux_knowledge/04gdb调试core文件$ g++ -o demo demo.cpp -g
kevein@kevein:~/Cpp_project/Linux_knowledge/04gdb调试core文件$ ls
demo  demo.cpp  gdb_debugging_core.md
kevein@kevein:~/Cpp_project/Linux_knowledge/04gdb调试core文件$ ./demo
Segmentation fault (core dumped)
kevein@kevein:~/Cpp_project/Linux_knowledge/04gdb调试core文件$ ls -a  //发现没有产生core文件
.  ..  demo  demo.cpp  gdb_debugging_core.md

kevein@kevein:~/Cpp_project/Linux_knowledge/04gdb调试core文件$ gdb demo
...
(gdb) r
...
Program received signal SIGSEGV, Segmentation fault.
0x0000555555555304 in bb (bh=3, xm="冰冰") at demo.cpp:8
8         *ptr=3;
(gdb) bt  //查看函数调用栈
#0  0x0000555555555304 in bb (bh=3, xm="冰冰") at demo.cpp:8
#1  0x0000555555555362 in aa (no=8, name="西施") at demo.cpp:14
#2  0x000055555555541c in main () at demo.cpp:19
(gdb) q
A debugging session is active.

        Inferior 1 [process 36807] will be killed.

Quit anyway? (y or n) n
Not confirmed.

(gdb) bt
#0  __strcpy_evex () at ../sysdeps/x86_64/multiarch/strcpy-evex.S:233
#1  0x0000555555555362 in bb (bh=3, xm="冰冰") at demo.cpp:9
#2  0x00005555555553bd in aa (no=8, name="西施") at demo.cpp:14
#3  0x0000555555555477 in main () at demo.cpp:19
(gdb) q
...
```

发现设置core文件size后并没有生成core文件，可能是操作系统原因或者错误问题简单，不适合生成core文件，在gdb中使用bt打印了函数调用栈，定位到原因。

