//Author: Dev Agrawal (201ME169) 
//PROCESS 1

#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	int in,i ;

	key_t key = 6000;
	//Obtaining Access to shared memory
	int shmid =  shmget(key, 27, 0666);
	if(shmid<0)
	{
		perror("Reader Error: Access Problem");
		return 0;
	}
 
	//Attaching the shared memory
	 char *shm = (shm = shmat(shmid, NULL, 0)); 
        
	if(shm=="-1")
	{
		perror("Reader Error: Problem in attaching");
	        return 0;
	}
	
	char *s = shm;	
	while((char)(*s)!='1')
		{
			//do nothing
		}

	//Reading what writer inserted into the shared memory...!!
	printf("Reader Read: ");	
	for (s = shm + 1; *s!='\0'; s++)
    {	
		char c = *s;
		putchar(c);
	}    	
	*shm='0';  
	printf("\n");
	return 0;
}