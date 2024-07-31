#include <unistd.h>
#include <iostream>
using namespace std;

int main(){
    int a = 5;

    pid_t pid = fork(); //创建子进程，返回两次，子进程返回值是0，父进程返回子进程的进程ID
    
    //父进程执行的代码
    if(pid > 0){
        a++;
        cout << "parent process" << "a = " << &a  << "," << a << endl;
        pid_t ppid = getpid();
        printf("parent pid: %d\n", ppid);
        return 0;
    }
    
    else{  //子进程创建一个shell进程
        sleep(5);
        execl("bin/python", "python", "3+3" , (char*)NULL); //子进程替换
        perror("execl");
    }
    

}