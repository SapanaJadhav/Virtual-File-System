#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fs.h"
SB sblk;
DEntry d1;
inode in1;
char buff2[1000];
int j;
void my_read(int fd,char *buff)
{
	int hash_cnt=0,myfd;
	char ch2,token[100];
	//printf("IN Read ");
	//mycnt=in1.i_ino-3;
	fp1=fopen("demo1.txt","r");	
	//printf("\nIn read function\n");
	if(fp1==NULL)
       {
		printf("\nNot able to open...");
	}
	else
	{
		fseek(fp1,0,SEEK_SET);
		ch2=fgetc(fp1);
		//printf("\n %c",ch2);
		
		myfd=atoi(&ch2);
		//printf("\n%d",myfd);
		//printf("%d",fd);
		/*if(myfd==fd)
		{
			printf("\nmy if");
			ch2=fgetc(fp1);
			printf("%c",ch2);
			while(ch2!='#')
			{
				ch2=fgetc(fp1);
				printf("%c",ch2);
				//ch2=fgetc(fp1);
			}
		}
*/

                 while(myfd!=fd)
		{
			//printf("\nmy if");
			ch2=fgetc(fp1);
			//printf("%c",ch2);
		        myfd=atoi(&ch2);
                         if(fd==myfd)
                         break;
                }





              //printf("SECOND");
              
		if(myfd==fd)
		{
                         //printf("in else");																		");
			ch2=fgetc(fp1);
                        printf("%c",ch2);
		//	myfd=atoi(&ch2);
			//while(myfd==0)
		//	{
		//		printf("\nmy while");
		//		ch2=fgetc(fp1);
		//		myfd=atoi(ch2);
		//	}
		//	if(myfd==fd)
		//	{
			//printf("\nmy if");
				ch2=fgetc(fp1);
				printf("%c",ch2);
				while(ch2!='#')
				{
					ch2=fgetc(fp1);
                                          if(ch2=='#')
                                         break;
					printf("%c",ch2);
                                      
					//ch2=fgetc(fp1);
				}
			}	
		}
//	}	
	fclose(fp1);		

}
