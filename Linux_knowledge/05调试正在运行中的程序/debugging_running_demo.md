# 调试正在运行中的程序

```
g++ -o demo demo.cpp -g //调试模式编译

./demo 运行编译后的程序

//新开一个terminal
ps -ef |grep demo  
/* 
ps显示进程状态,-ef表示所有进程的详细信息
|将ps命令输出传送给给grep的输入
grep查找出包含demo的进程
*/

gdb demo -p 进程id //调试运行中的程序

bt //查看函数调用栈

```