#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "voiceOutput/stdVout.h"
#include "sysCmdRecon.h"
//By Simbad el Marino 03/12/2014
//v1.0
int readIOfile(char file[],char meme[],char entry[]);
int writeIOfile(char file[], char meme[]);

//Comment main section when finish testing so it can be used as header file
int main(void)
{
char question[50]="";
int ret =0;
printf("Hello Human...\n");
while(1)
{
   
	printf("Q:");
	//scanf("%s",&question);
	scanf("%*c%[^\n]",question);
	//printf("%s",question);
	reconSystemCmd(question);
	ret = readIOfile("dictionaries/dict.txt",question,"1");
	//printf("return:%d",ret);
	if(!ret)
	writeIOfile("dictionaries/dict.txt",question);
	printf("------------------------------------------------\n");
	memset(question,0,sizeof(question));
	}
}


int writeIOfile(char file[], char meme[])
{
	FILE *fa;	//file pointer
	char newMemeAns[50]="";
	int c=0;
	printf("################################################\n\n");
	printf("No suitable answer was found for %s,\n please write one now\n",meme);
	scanf("%*c%[^\n]",&newMemeAns);
	printf("New meme is: %s\n",meme);
	printf("New meme is answer is: %s\n",newMemeAns);
	printf("################################################\n\n");
	
	  if((fa=fopen(file,"a+"))==NULL) 
      {
		printf("Cannot open file.\n");
		return 0;
 	  }
 	  
     /*while((c = fgetc(fa) ) != EOF)
     {
     	//Go to end of file
     }*/
     fprintf(fa,"\n");
     fprintf(fa,"[");
     fprintf(fa,meme);
     fprintf(fa,"]");
     fprintf(fa,"\n1=");
     fprintf(fa,newMemeAns);
     fprintf(fa,"\n");
     fclose(fa);
	 return 1;

}

int readIOfile(char file[],char meme[],char entry[])
{
	FILE *fp ; //file pointer
	int c=0;
	int sectionfound=0;
	int firstCharDetected = 0;
	char sectionString[50]="";
	int i=0;
	int memefound=0;
	long seek_position;
	char entryString[100]="";
	char valueString[100] = "";
	
      
      if((fp=fopen(file,"r"))==NULL) 
      {
		printf("Cannot open file.\n");
		return 0;
 	  }
 
  while(((c = fgetc(fp)) != EOF) && (memefound == 0)) {
  
  
   
     if(c == '[')			//###Check if section Start is detected
	  	 {
	  	 sectionfound = 1;
	  	 firstCharDetected = 1;
	  	 c = fgetc(fp);
	  	// printf("\nI found a [ !!\n");
	  	 }
	  	 
	  	 
	  	 
	 
	 if(c == ']')			//###Check if section end is detected
	 {
	    i=0;								//Reset i var in order to accept a new section
	    //printf("Current String is: %s",sectionString);
	 	sectionfound = 0;
	 	/*if(!strcmp(sectionString,"adios"))
		 	{
		 		return 1;
		 	}
		
		if(!strcmp(sectionString,"shutdown"))
		{
			system("echo Shutting down system");
		}*/
	 	
	 	if(!strcmp(sectionString,meme))
	 	{
	 	//
	 	//strcpy(sectionString,"");
	 	//printf("\nQ:%s",sectionString);
	 	//printf("\nEnd of section\n");
	 	//fgetpos(fp, &file_pos);
	 	//printf("\nPosition of char is: %i",ftell(fp));
	 	seek_position = ftell(fp)+1;
	 	fseek(fp, 0L, SEEK_SET);
        fseek(fp, seek_position, SEEK_CUR );
	 //	printf("\nPosition of entry is: %i",ftell(fp));
	 	memefound = 1;
	 	//return 1;
	 	while(strcmp(entryString,entry) != 0)
	 	{
		 	 while((c = fgetc(fp) ) != '=')
		 	 {
		 	 	//printf("%c",c);
		 	 	entryString[i] = c;
		 	 	i++;
		 	 }
		 	 i = 0;
		 	 //printf("StringEntry: %s",entryString);
		 	 if(!strcmp(entryString,entry))
		 	 {
		 		 while((c = fgetc(fp) ) != '\n')
		 	 		{	
				 	 //printf("%c",c);
				 	 valueString[i] = c;
				 	 i++;
				 	}
		 	 }
	 	 
	 	 
		 	 else
		 	 {
		 	 
			 	 while((c = fgetc(fp) ) != '\n')
			 	 {
			 	   //printf("%c",c);
			 	 	//Do nothing
			 	 }
		 	 }
	 	 }
	 	
	 
	 	 printf("\n");
	 	 //printf("%s\n",entryString);
	 	 printf("A:%s",valueString);
	 	 //speakEs(valueString);
	 	 //speakEng(valueString);
	 	 printf("\n");
	 	}
	 	 else
	 {
	 	//memefound=0;
	 	//return 0;
	 }
	 	
	 }
	
	 
	 if(sectionfound == 1)
	  {
	  	//printf("%c", c);
	  	if(firstCharDetected)		//Clear sectionString array on each start of a new section
		  	{
		  		memset(sectionString,0,strlen(sectionString));
		  		firstCharDetected = 0;
		  	}
	  	
	  	sectionString[i] = c;
	  	i++;					//Increment i in order to be go through completion of string
	  	
	  }
	 
  }
	
	fclose(fp);
	memset(sectionString,0,sizeof(sectionString));
	memset(entryString,0,sizeof(entryString));
	memset(valueString,0,sizeof(valueString));
	switch(memefound)
	{
		case 0:		return 0;
					break;
					
		case 1:		return 1;
					break;
	
	
	}

}
