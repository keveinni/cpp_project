#include <iostream>
using namespace std;


int main(int argc, char *argv[], char *envp[]){

    // // 显示参数个数
    // cout << "一共有" << argc << "个参数" << endl;

    // // 显示全部参数 
    // for (int i=0; i< argc; i++){
    //     cout << "第" << i << "个参数为" << argv[i] << endl;
    // } 

    // for (int i=0; envp[i]!=0;  i++){  // 环境变量最后一个参数为0
    //     cout << envp[i] << endl;
    // } 

    // return 0;

    setenv("AA", "aaa", 0);
    cout << "AA=" << getenv("AA") << endl;
    return 0;
}