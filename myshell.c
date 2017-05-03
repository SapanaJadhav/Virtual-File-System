#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
char *str,*saveptr,cmd[50],*token[34];
int i,pid;
system("clear");
while(1)
{
printf("sapana@");
strcpy(cmd,"\0");
gets(cmd);

loop1:   if((strcmp(cmd,""))==0);
            {
           printf("sapana@ ");
           gets(cmd);
            if((strcmp(cmd,""))==0);
            goto loop1;
}
if((strcmp(cmd,"exit"))==0)
 {
   printf("exit........");
   exit(0);
}
for(i=0,str=cmd;;i++,str=NULL)
{
 token[i]=NULL;
strtok_r(str," ",&saveptr);}
if(token[i]==NULL)
{
break;
}
if(!(pid=fork())){
			execvp(token[0],token);		//execute the command
			perror(token[0]);		

}

else if(pid>0)
	{		waitpid(pid);	
        } 
return 0;
}
}

