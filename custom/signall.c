#include "./wrapper/csapp.h"

void handler(int sig){
    int olderrno=errno;
    if(waitpid(-1,NULL,0) <0){
        Sio_puts("wait error");
    }

    Sio_puts("Handler reaped child\n");
    Sleep(1);
    errno=olderrno;
}

void handler2(int sig){
    int olderrno=errno;
    while(waitpid(-1,NULL,0) >0){
    Sio_puts("Handler reaped child\n");
    }
    if (errno!=ECHILD)
        Sio_puts("wait error"); 

    Sleep(1);
    errno=olderrno;
}


int main(void){
    int i,n;
    char buf[MAXBUF];

    if(signal(SIGCHLD,handler2)==SIG_ERR){
        unix_error("signal error");
    }

    for(i=0;i<3;i++){
        if(Fork()==0){
            printf("Hello,from child %d\n",(int)getpid());
            exit(0);
        }
    }

    if((n=read(STDIN_FILENO,buf,sizeof(buf)))<0){
        unix_error("read error");
    }

    printf("parent processing input\n");
    while(1);
    exit(0);
}