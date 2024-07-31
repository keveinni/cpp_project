#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

void EXIT(int sig){
    cout << "收到了信号：" << sig <<endl;
    cout << "正在释放资源" << endl;
    cout << "程序退出" << endl;
    exit(0);
}

void func(int sig){
    cout << "收到了信号：" << sig << endl;

}

int main(){

    // 忽略所有信号
    for (int i=1; i <= 64; i++){
        signal(i, SIG_IGN);
    }

    signal(2, func);
    signal(15, EXIT);

    while(true){
        cout << "执行一次任务" << endl;
        sleep(1);
    }
    
}