#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

void fun0();    // wait()结束子进程。在子进程结束前，父进程将被阻塞。
void fun1();    // 观察僵尸进程
void fun2();    // 使用信号结束僵尸进程
void fun3(int sig);    // fun2接受信号后的处理函数

int main(){
//    fun1();
//    fun0();
fun2();
}


void fun0(){
    if(fork() > 0){
        //父进程
        int sts;
        pid_t pid = wait(&sts);
        cout << "已终止的子进程编号是：" << pid << endl;
        if (WIFEXITED(sts)){
            cout << "子进程正常退出，退出状态是：" << WEXITSTATUS(sts) << endl;
        }else{
            cout << "子进程异常退出，退出状态是：" << WTERMSIG(sts) << endl;
        }
    }else{
        //子进程
        int *p = 0;
        *p = 10;    // 异常结束代码
        exit(1);

    }
    
}

void fun1(){
    pid_t pid = fork();
    
    //父进程终止
    if (pid > 0){
        cout << "parent process" << getpid() << "is runing " << endl;
        exit(0);
    }
    // 子进程成为僵尸进程
    else{   
        for (int i=0;i<100;i++){
            cout << "child process"<< getpid() << "is running " << endl;
            sleep(1);
        }
    }
}

void fun2(){
    signal(SIGCHLD, fun3);  //SIGCHLD信号，当子进程结束时，父进程会收到此信号
    if (fork() > 0)
    {
        while(true){
            cout << "parent process" << getpid() << "is runing " << endl;
            sleep(1);
        }
    }
    else{
        sleep(5);
        // int *p = 0;
        // *p = 1; //异常结束代码
        exit(1);
    }
}

void fun3(int sig){
    int sts;
    pid_t pid = wait(&sts);
    cout << "已终止的子进程编号是：" << pid << endl;
    if (WIFEXITED(sts)){
        cout << "子进程正常退出，退出状态是:" << WEXITSTATUS(sts) << endl;
    }
    else{
        cout << "子进程异常退出。退出状态是:" << WTERMSIG(sts) << endl;
    }
}