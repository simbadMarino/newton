#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


int reconSystemCmd(char sysCmd[]);


int reconSystemCmd(char sysCmd[])
{
  int cmdchooser=0;
  int processID = 0;
   
	if(!strcmp(sysCmd,"adios"))
	{
		cmdchooser = 1;
	}
	
	else if(!strcmp(sysCmd,"bye"))
	{
		cmdchooser = 2;
	}
	
	else if(!strcmp(sysCmd,"good bye"))
	{
		cmdchooser = 3;
	}
	
	else if(!strcmp(sysCmd,"reiniciar sistema"))
	{
		cmdchooser = 4;
	}
	
	else if(!strcmp(sysCmd,"reboot system"))
	{
		cmdchooser = 4;
	}
	
	
	
	switch(cmdchooser)
	{
		
		case 1:	printf("\n Adios amo");
				printf("\nProcess Killed ID: %d\n", getpid());
				processID = getpid();
				kill(processID, SIGTERM);
				return 1;
				break;
		
		case 2: printf("\n Bye master");
				printf("\nProcess Killed ID: %d\n", getpid());
				processID = getpid();
				kill(processID, SIGTERM);
				return 1;
				break;
		
		case 3: printf("\n Good Bye master");
				printf("\nProcess Killed ID: %d\n", getpid());
				processID = getpid();
				kill(processID, SIGTERM);
				return 1;
				break;
				
		case 4: printf("\nRebooting system");
				system("sleep 5");
				system("reboot");
				return 1;
				break;
				
		default: return 0;
	
	}



}


