#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"fs.h"
SB sblk;
inode in1;
//char buff[nn];

int my_open(char fname[50],char m)
{
	//printf("\nmy open..");
   	int fd,bytes=0;
   	char *fname1;
   
	in1.mode1=m;
	fd=my_namei(fname);
	if(fd==-1)
        	printf("File Does not Exist...");
	else
	{
        	if(m=='w')
		{
			in1.mode1=m;
			//printf("\n in myopen:");
                        my_write(fd,data_block,bytes);
                   	return;
               }
                          
        	if(m=='r')
               {
			in1.mode1=m;
        		printf("\nfile contents are:\n");
                        my_read(fd,buff);
                      return;
                }
              
              
        //      printf("\n Enter r/w\n");
         }
       
       return ;
}
