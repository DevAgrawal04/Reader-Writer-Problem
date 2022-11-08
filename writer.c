//Author: Dev Agrawal (201ME169) 
// PROCESS 0

#include<stdio.h>
#include <sys/ipc.h> //inter process communication
#include <sys/shm.h> //shared memory
#include<string.h>
int main(void)
{
	int in,i,count=0;
	key_t key = 6000;
	//Obtaining Access to shared memory
	int shmid = shmget(key, 27, IPC_CREAT | 0666);
	if(shmid<0)
	{
		perror("Writer Error: Access Problem");
		return 0;
	}
 
	//Attaching the shared memory
	char *shm = shmat(shmid, NULL, 0); 

	if(shm=="-1")
	{
		perror("Writer Error: Problem in attaching");
	        return 0;
	}

	char str[26];
	for (int i=0; i<26; i++){
		str[i] = (char)(i+65);
	}
	
	int n = 5;
	printf("Enter the number of Writer Process Cycles: ");
	scanf("%d",&n);
	printf("Waiting for reader \n");

	while(count < n){     //writer writes into the memory 4 times. 

		//Inserting str into the shared memory..!!
			char *s = shm;

			while((char)(*s) == '1')
			{
				//do nothing
			}
			
			*s++; //First position is reserved for mutex.
			printf("Writer Wrote: ");
			for (i=0;i<26;i++)
			{
				char c = str[((i+count)%26)];	
				putchar(c);	//Prints the text onto the terminal
				*s++ = c;
			}
			*s = '\0';	
			printf("\nTurn set to reader \n\n");
			*shm='1'; //set turn to reader
			count++;
	}
}