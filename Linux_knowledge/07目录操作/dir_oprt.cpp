#include <iostream>
#include <unistd.h>  // 获取、创建、删除、切换当前目录的函数头文件
#include <sys/stat.h>  // 创建目录的函数头文件
#include <dirent.h>  //获取文件中目录列表的函数的头文件
#include <cstring>  //strcpy函数的头文件
#include <cerrno>   //cerrno头文件
#include <cstdlib>

using namespace std;

int learn_dir();

int main(){
   return learn_dir();
   
}

int  learn_dir(){
    // 获取当前工作目录
    char path1[256];
    if (getcwd(path1, 256) == nullptr) {
        cerr << "无法获取当前工作目录" << endl;
        return -1;
    }


    cout << "path1 = " << path1 << endl;


    //获取目录中文件的列表
    DIR *dir = opendir(path1);  // 定义目录指针
    if (dir == nullptr) {
        cerr << "无法打开目录" << path1 << endl;
        return -1;
    }

    struct dirent *stdinfo = nullptr;
    while((stdinfo = readdir(dir)) != nullptr){
        cout << "文件名=" << stdinfo -> d_name << ", 文件类型" <<(int)stdinfo -> d_type << endl;  
    }

    closedir(dir);

    //创建目录
    char new_dir[256];
    strcpy(new_dir, path1);
    strcat(new_dir, "/new_dir");
    if (mkdir(new_dir, 0755) != 0){
        cerr << "无法创建目录" << new_dir << endl;
        return -1;
    }


    //切换工作目录到创建的目录
    if(chdir(new_dir) != 0){
        cerr << "无法切换到目录" << new_dir << endl;
        return -1;
    
    }
   
    //获取切换目录后的当前工作目录   
    char *path2 = get_current_dir_name();
    if(path2 == nullptr){
        cerr << "无法获取当前工作目录" << endl;
        return -1;
    }
    cout << "path2 = " << path2 << endl;
    free(path2); //释放内存


    //切换回原来的目录
    if (chdir("..") !=0){
        cerr << "无法切换回原来的目录" << endl;
        return -1;
    }

    //删除目录
    if(rmdir(new_dir) != 0){
        cerr << "无法删除目录" << new_dir << endl;
        return -1;
    }

    return 0;
}