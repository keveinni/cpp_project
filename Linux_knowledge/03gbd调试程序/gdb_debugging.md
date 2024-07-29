# gdb调试

## 调试流程
**要使用调试，必须在编译时加入-g 选项**

```
g++ -o demo demo.cpp -g
```

|常用命令|命令说明|
|---|---|
|**gdb** demo|进入调试demo程序|
|**set args** aa bb cc|设置参数为aa bb cc|
|**b** n|在第n行设置断点|
|**r**|运行调试|
|**n**|运行一行|
|**c**|运行到下处断点|
|**s**|不进入调用内部|
|**p**|打印变量的名、也能进行赋值|
|**set var**| 设置变量的值|
|**q**|退出调试|

## 调试实例

```
kevein@kevein:~/Cpp_project/Linux_knowledge/gbd调试程序$ gdb demo  //开始调试
...
(gdb) set args aa bb 我喜欢你  //设置参数
(gdb) b 22
Breakpoint 1 at 0x143a: file demo.cpp, line 22.
(gdb) b 28
Breakpoint 2 at 0x1497: file demo.cpp, line 28.
(gdb) r
Starting program: /home/kevein/Cpp_project/Linux_knowledge/gbd调试程序/demo aa bb 我喜欢你  //开始运行

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n  //n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
表白前的准备工作一。
表白前的准备工作二。
表白前的准备工作三。
表白前的准备工作四。
表白前的准备工作五。

Breakpoint 1, main (argc=4, argv=0x7fffffffddd8, envp=0x7fffffffde00) at demo.cpp:22  //到达断点
22        show(argv[1],argv[2],argv[3]);
(gdb) n
aa开始表白。
bb：我喜欢你
24        cout << "表白完成。\n";

(gdb) n
表白完成。
26        for (int ii=0;ii<10;ii++)
(gdb) n

Breakpoint 2, main (argc=4, argv=0x7fffffffddd8, envp=0x7fffffffde00) at demo.cpp:28
28          string str="这是第"+to_string(ii)+"个超级女生。";
(gdb) p ii
$1 = 0
(gdb) p ii=9  //赋值语句 跳过循环
$2 = 9
(gdb) n
29          cout << str << endl;
(gdb) m
Ambiguous command "m": macro, maintenance, make, mem, memory-tag, monitor, mt.
(gdb) n
这是第9个超级女生。
30        }
(gdb) n
26        for (int ii=0;ii<10;ii++)
(gdb) n
32        return 0;
(gdb) n
33      }
(gdb) n
__libc_start_call_main (main=main@entry=0x55555555535e <main(int, char**, char**)>, argc=argc@entry=4, 
    argv=argv@entry=0x7fffffffddd8) at ../sysdeps/nptl/libc_start_call_main.h:74
warning: 74     ../sysdeps/nptl/libc_start_call_main.h: No such file or directory
(gdb) q  //退出调试
A debugging session is active.

        Inferior 1 [process 26840] will be killed.

Quit anyway? (y or n) y
```