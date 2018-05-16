#include "./wrapper/csapp.h"
#include <unistd.h>
int main(void){
    printf("here is parent!\n");
    char *argv[2] = {};
    char *envp[2] = {};
    execve("exe", argv, envp); //这里执行了之后将不再返回
    printf("hello");
    return 0;
}