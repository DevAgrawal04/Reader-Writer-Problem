#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

const int SHMSZ=1000;

int main(void)
{
    int sid;
    key_t key;
    char *sbuff;
    if((key = ftok("/desk/abc",'a'))==-1)
    { 
        printf("ftok error");
    }
    /*shared memory id*/
    if((sid=shmget(key,SHMSZ,0644/IPC_CREAT))==-1)
    {
        printf("shmget error");
    }
    // P1.C-WRITING TO MEMORY
    // Write a program to get a string from the keyboard and write into memory. Also write another 
    // program to read from the memory.
    if((sbuff= (char*)shmat (sid, NULL, SHM_RDONLY)) == (char*) -1)
    {
        printf("shmat error");
    }
    memcpy(sbuff,"HELLO",5);
    sleep(30);
}
