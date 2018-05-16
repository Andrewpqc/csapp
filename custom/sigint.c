#include "./wrapper/csapp.h"

void sigint_handler(int sig){
    printf("Caught SIGINT\n");
    // exit(1);
    return;
}

int main(void){
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        unix_error("signal error");
    pause();
    printf("hhh23333");
    return 0;
}