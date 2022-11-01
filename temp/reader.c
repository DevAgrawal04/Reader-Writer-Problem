#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
const int SHMSZ=100;
int main(void)
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    /*shared memory id*/
    if((shmid=shmget(4678,SHMSZ, 0)) == -1)
    {
        printf("shmget error");
    }
    if((shm=shmat(shmid,NULL, 0)) == )
    {
        printf("shmat error");
    }
    printf("message read is %s",shm);
    shmdt(shm);
}