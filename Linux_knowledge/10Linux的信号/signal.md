# 信号
Linux的信号是一种异步通信机制，用于通知进程发生了某种事件。信号可以由内核产生，也可以由其他进程产生。信号的处理方式可以是忽略、捕获或者执行默认操作。

## 信号类型
Linux定义了多种信号，每种信号都有一个唯一的编号和一个名称。常见的信号包括：

- `SIGINT`：中断信号，通常由用户按下Ctrl+C产生。
- `SIGQUIT`：退出信号，通常由用户按下Ctrl+\产生。
- `SIGKILL`：终止信号，无法被忽略、捕获或者阻塞。
- `SIGTERM`：终止信号，可以由用户或者程序发送，用于优雅地终止进程。

## 发送信号
在终端中使用kill、killall命令可以向进程发送信号。

```bash
kill -signum pid
```

## 捕获信号
在程序中可以使用signal函数来捕获信号。

```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int signum) {
    printf("Received signal %d\n", signum);
    exit(signum);
}

void func(){
    printf("hello world\n");
};

int main() {
    signal(SIGINT, handler); //SIGINT是信号编号，handler是信号处理函数，
    signal(SIGQUIT, func); //可以将自定义的函数作为信号处理函数
    signal(SIGKILL, SIG_IGN); //SIGKILL无法被捕获，SIG_IGN表示忽略信号
    signal(SIGTERM, SIG_DFL.); //SIGTERM的默认操作是终止进程，SIG_DEF表示执行默认操作

    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}
```

## 忽略信号
在程序中可以使用signal函数来忽略信号。

```c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int signum) {
    printf("Received signal %d\n", signum);
    exit(signum);
}

void func(){
    printf("hello world\n");
};

int main() {
        
    

    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}
```

信号处理函数可以是自定义的处理函数\，也可以是系统提供的默认处理函数。默认处理函数包括：

- `SIG_IGN`：忽略信号。
- `SIG_DFL`：执行默认操作。

