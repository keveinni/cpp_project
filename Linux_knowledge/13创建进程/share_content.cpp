#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main(){
    ofstream fout;
    fout.open("share.txt");
    vfork();
    for (int i = 0; i < 1000; i++){
        fout << "进程" << getpid() << "写入第" << i << "行" << endl;
    }
    fout.close();
    return 0;
}