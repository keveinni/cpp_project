#include <iostream>
#include <cstring>
#include <cerrno>
#include <sys/stat.h>
using namespace std;

int main(){
    int  iret = mkdir("/home/kevein/Cpp_project/Linux_knowledge/08Linux系统错误/new_dir/", 0755);
    if(iret != 0){
        cout << "iret=" << iret <<"\nmkdir error" << endl;
        cout << "errno: " << errno << endl;
        cout << "strerror: " << strerror(errno) << endl;
    }

    iret = mkdir("/home/kevein/Cpp_project/Linux_knowledge/08Linux系统错误/new_dir/", 0755);
    if (iret != 0){
        cout << "iret=" << iret <<"\nmkdir error" << endl;
        cout << "errno: " << errno << endl;
        perror("mkdir error:");
    
    }


}