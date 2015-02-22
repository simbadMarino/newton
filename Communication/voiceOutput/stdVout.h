#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//By Simbad el Marino 03/12/2014
//v1.0

int speakEng(char phrase[]);
int detectVoicecmd(char voicCmd[]);
int speakEs(char phrase[]);



int speakEng(char phrase[])
{
int retSys;
char cmd[150] = "espeak -p 40 -s 130 \"";	//Speaking with  pitch 40 and speed 130

	strncat(cmd, phrase, 150);
	strncat(cmd, "\"",150);
	printf("\nSpeaking now...\n%s",cmd);
	retSys = system(cmd);								//Output to shell script cmd
	if(retSys == 0)
		return 1;	//On succesful call for espeak return 1
	else
	{
		return 0;	//On unsuccesful call for espeak return 0
		printf("\nReturn Value from systemCall: %d",retSys);
	}
}



int speakEs(char phrase[])
{
int retSys;
char cmd[100] = "espeak -ves-la \""; 

	strncat(cmd, phrase, 100);
	strncat(cmd, "\"",100);
	printf("\nPronunciando ahora...\n%s",cmd);
	retSys = system(cmd); 
	if(retSys == 0)
		return 1;	//On succesful call for espeak return 1
	else
	{
		return 0;	//On unsuccesful call for espeak return 0
		printf("\nReturn Value from systemCall: %d",retSys);
	}



}

int detectVoicecmd(char voicCmd[])
{
int ret;

	ret = strcmp(voicCmd,"newton");
	
	switch (ret)
	{
		case 0:	printf("\n\n###Newton is ready to accept any request :) ###");
				return 1;
				startVoiceRecon();
				
				break;
		
		default:	printf("\nNewton keyword was not detected before tCmdReady or wrong phrase commanded, string detected was: %s \n",voicCmd);
				return 0;
				break;
				
	}
	
}




















