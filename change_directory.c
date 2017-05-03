#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"fs.h"

int my_create(char *filename);
SB sblk;
DEntry d1[21][6];
inode in1;

inode in1;
int tempfilecnt,fd,k1,i,k2,i,j;
int change_directory(char *filename,int cdflag)
{

	char *myvar1;
	char cmd1[50];
	char  *str1,*tok1[10],saveptr1[50];
	myvar1=(char *)&saveptr1;
	cdflag=1;
	k2=sblk.dircnt;
	char dirname[14],*token;
	strcpy(dirname,filename);
	tempfilecnt=sblk.filecnt;
	while(1)
	{
		printf("\nMYSHELL/%s::",filename);
		strcpy(cmd1,"\0");
		gets(cmd1);
		
		for (i = 0, str1 = cmd1; ;i++, str1 = NULL) 
		{
			tok1[i]=NULL;
      			tok1[i] = strtok_r(str1, " ",&myvar1);
              		if (tok1[i] == NULL)
                  		break;
               	}
		 if((strcmp(cmd1,"create"))==0)
 		{
   	 		c_r_val=my_create(tok1[1]);
			if(c_r_val==-1)
				printf("\nInvalid Filename ...!!!\n");
			else
			{
				printf("%d\n",c_r_val);
				sblk.filecnt++;
				mk_entry(tok1[1],c_r_val);
 			}
		}
		else if(strcmp(cmd1,"ls")==0)
		{
			for(j=tempfilecnt; j<sblk.filecnt; j++)
			{
        			printf("%d\t\t\t\t%s",d1[k2][j].inode_num,d1[k2][j].fname);
         			printf("\n");
        		}
	
        
		}
		
		
                else if(strcmp(cmd1,"cd")==0)
		{
                     if(strcmp(tok1[1],"..")==0)
			return 0;
		}
	}
}		
