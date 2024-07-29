#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>

using namespace std;


//将tm结构体转换为中式显示格式
string time2String(const tm *tmnow){

    if(tmnow == nullptr){
        return "";
    }

   string stime = to_string(tmnow->tm_year + 1900) + "-"
    + to_string(tmnow->tm_mon + 1) + "-"
    + to_string(tmnow->tm_yday) + " "
    + to_string(tmnow->tm_hour) + ":"
    + to_string(tmnow->tm_min) + ":"
    + to_string(tmnow->tm_sec) ;
    return stime;
     
}

void learn_mktime(){
     // 获取当前时间 1969.01.01至今的秒数
    time_t now = time(nullptr);
    cout << "now=" << now << endl;

    //将整数时间转换为tm结构体
    tm tmnow;
    localtime_r(&now, &tmnow);

    //根据tm结构体拼写字符串格式时间
    string stime = time2String(&tmnow);
    
    cout << "stime=" << stime << endl;

    time_t start_time = mktime(&tmnow);  //将时间转换为time_t(long)类型
    start_time += 29 *60; // 时间加30min
    localtime_r(&start_time, &tmnow);  //time_t类型转换为tm结构体
    stime = time2String(&tmnow);
    cout << "stime=" << stime <<endl;
}


int main(){
    learn_mktime();
    sleep(10);
    learn_mktime();

    return 0;
}