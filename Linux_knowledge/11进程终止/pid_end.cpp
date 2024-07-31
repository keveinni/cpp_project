#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

// void fun1(){
//     cout << "fun1" <<  endl;
//     // exit(0); //终止进程
//     return;
// }

// void fun2(){
//     cout << "fun2" << endl;
//     fun1();
//     cout << "fun2 end" << endl;
// }

// struct AA{
//     string name;
//     AA(const string &name):name(name){}
//     ~AA(){
//         cout << name << "::~AA()" << endl;
    
//     }
// };

// AA a("a");

// int main(){
//     AA b("b");
//     // exit(0);  //exit()终止进程析构全局变量
//     // return 0;    //return终止进程析构全局变量和局部变量
//     // _exit(0); // _exit()终止进程不析构全局变量和局部变量
//     abort(); //abort()终止进程不析构全局变量和局部变量，并且产生core文件
// }

void fun1(){
    cout << "fun1" << endl;
}

void fun2(){
    cout << "fun2" << endl;

}

int main(){
    atexit(fun1);
    atexit(fun2);
    exit(0);
}