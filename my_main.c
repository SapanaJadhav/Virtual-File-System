#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"fs.h"

int main()
{
	char *cmd[25],*str[100],*fileName,*temp[25],*temp1;
  	int i=0,len=0,j,offset,fd,*arr,*alloc_arr,cnt1,flag,k,l;//read;
  	system("clear");
      	//str[strlen(str)]='\0';
  	
	struct superblock *sb;
  	struct inode *in;

  	while(1)
    	{
      		printf("\n $ MyShell$ ");
      		gets(str);     
      		cmd[i]=strtok(str," ");
      
      		while(cmd[i] != NULL)
		{ 
	  		i++;
	  		cmd[i]=strtok(NULL," "); 
		}
      		/*if(strcmp(cmd[0],"mkdir")==0)
	      	{
			mkdir1(cmd);
	      	}*/
	    	if(!strcmp(cmd[0],"my_creat"))
		{
		  	my_create(cmd);
		}
	      	/*else if(!strcmp(cmd[0],"open"))
		{
		    	open1(cmd);
		}
		else if(!strcmp(cmd[0],"write"))
		{
		    	write1(cmd);
		}
		else if(!strcmp(cmd[0],"exit"))
		{
		      	my_write1();
		      	exit(0);
		}     
      		i=0;*/
    	}
  return 0;
}
