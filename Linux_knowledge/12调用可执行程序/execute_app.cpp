#include <stdlib.h> // system()函数头文件
#include <stdio.h>
#include <unistd.h>
using namespace std;

// int main(){
//     // system()函数调用可执行程序
//     if(system("python3 test.py")!=0){
//         perror("system error");
//     }
//     return 0;
    
// }


int main(){
    
    // int res = execl("/bin/python3", "python3", "/home/kevein/Cpp_project/Linux_knowledge/12调用可执行程序/test.py", (char *)NULL);
    // printf("res = %d\n", res);
    // perror("execl error");

    const char *args[10];
    args[0] = "python3";
    args[1] = "/home/kevein/Cpp_project/Linux_knowledge/12调用可执行程序/test.py";
    args[2] = (char *)NULL;
    int res = execv("/bin/python3", (char* const*)args);
    // cout << "res = " << res << endl;
    printf("res = %d\n", res);
    perror("execv error");

}