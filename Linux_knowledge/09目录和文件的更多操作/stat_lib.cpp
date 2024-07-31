#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h> //utime函数头文件
#include <utime.h> //utime函数头文件
using namespace std;
int main(int argc, char *argv[]){
    //检查参数个数
    if (argc != 2){
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }
    //声明结构体变量
    struct stat st;

    //调用stat函数获取文件状态
    if (stat(argv[1], &st) != 0){
        perror("failed to read the file status"); 
        return -1;
    }else{
        if(S_ISREG(st.st_mode)){
            cout << "regular file:" << "mtime=" << st.st_mtime << "size=" << st.st_size << endl;
       }else if(S_ISDIR(st.st_mode)){
            cout << "regular dictory :" << "mtime=" << st.st_mtime << "size=" << st.st_size << endl; 
        }
    }

    //调用utime函数修改文件时间
    struct utimbuf ut;
    ut.actime = 2022020;
    ut.modtime = 20220220;
    utime(argv[1], &ut);
    stat(argv[1], &st);
    cout <<"atime：" << st.st_atime << ", mtime:" << st.st_mtime << "mtime" << st.st_mtime << endl;
    
    //调用rename函数重命名文件
    if (rename(argv[1], "demo") != 0){
        perror("failed to rename the file");
        return -1;
    }else{
        stat(argv[1], &st);
        cout << "rename success" << endl;
    }

    //调用remove函数删除文件
    if (remove("demo") != 0){
        perror("failed to remove the file");
        return -1;
    }else{
        cout << "remove success" <<endl;
    }
    
    return 0;
}