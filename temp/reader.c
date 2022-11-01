#include <stdio.h>
#include <sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
Const int SHMSZ=1000;
int main(void){
    int sid;
    key_t key;
    char *sbuff;
    
    /*shared memory id*/
    if((sid=shmget(key,SHMSZ,0)) == -1){
        printf("shmget error \n");
    }
    if((sbuff= (char*)shmat (sid, NULL, 0)) == (VOID*) -1){
        printf("shmat error \n");
    }
    printf("MESSAGE FROM P1 IS =%s", sbuff);
}