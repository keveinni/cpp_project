#include <unistd.h>
#include <iostream>
#include <string>
// #include <errno.h>
#include <stdio.h>
using namespace std;

//this demo.cpp is for learning check the file permission

int main(int argc, char *argv[]){

    if (argc == 0){
        cout << "please input the file path" << endl;
        return 0;
    }
    string file_path = argv[1];
    //check the file exist or not 
    if (access(file_path.c_str(), F_OK) == 0){
        cout << "file exist" << endl;
        // check the file can be read or not
        if (access(file_path.c_str(), R_OK) == 0){
        cout << "file can be read" << endl;
        }else{
            perror("file can not be read");
        }

        //check the file can be write or not
        if (access(file_path.c_str(), W_OK) == 0){
            cout << "file can be write" << endl;
        }else{
            perror("file can not be write");
        }

    // check the file can be execute or not
        if (access(file_path.c_str(), X_OK == 0)){
            cout << "file can be execute" << endl;
        }else{
            perror("file can not be execute");
        }
        // check the file can be read or not
        if (access(file_path.c_str(), R_OK) == 0){
            cout << "file can be read" << endl;
        }else{
            perror("file can not be read");
        }

        //check the file can be write or not
        if (access(file_path.c_str(), W_OK) == 0){
            cout << "file can be write" << endl;
        }else{
            perror("file can not be write");
        }

        // check the file can be execute or not
        if (access(file_path.c_str(), X_OK == 0)){
            cout << "file can be execute" << endl;
        }else{
            perror("file can not be execute");
        }
    }else{
        perror("file not exist");
        return 0;
    }
  
}
