#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"fs.h"

void disaplay_inode(char *fname);
void mk_initialize();
int my_ialloc(int no1);
int my_iget(int no);
int my_create(char *filename);
int my_mkdir(char *filename);
int my_namei(char *filename);
int my_open(char fname[50],char mode);
void disp_dir_content();
void my_write(int fd,char *buff,int bytes);
void my_read(int fd,char *buff);
void mk_entry(char tok[],int c_r_val);
int change_directory(char *,int);
void my_mount(FILE *fs);
SB sblk;
inode in1;
DEntry d1[21][11];
	

int main(int argc,char *argv)
{
	int cdflag=0;
	char *myvar;
	char  *str,cmd[50],*tok[10],saveptr[50];


	myvar=(char *)&saveptr;
	
	char one[]=".";
	char two[]="..";
	int pid,j,k1,k3;
	int myval;
	system("clear");
	FILE *fp1,*fs;
	int n,fd,i=1;
	mk_initialize();
	c_r_val=my_create(".");
	sblk.filecnt++;
	mk_entry(one,c_r_val);
	c_r_val=my_create("..");
	sblk.filecnt++;
	mk_entry(two,c_r_val);
	while(1)
	{
		printf("\nMYSHELL::");
		strcpy(cmd,"\0");
		gets(cmd);
		
		for (i = 0, str = cmd; ;i++, str = NULL) 
		{
			tok[i]=NULL;
      			tok[i] = strtok_r(str, " ",&myvar);
              		if (tok[i] == NULL)
                  		break;
               	}

		if((strcmp(cmd,"exit")==0) || (strcmp(cmd,"q")==0))
		{
   			printf("exit........\n");
   			exit(0);
		}
		else if((strcmp(cmd,"help")==0) || (strcmp(cmd,"h")==0))
		{
   			printf("\n create <filename>\t - to create file.");						//done
			printf("\n write <filename>\t - to write file.");						//done
			printf("\n cat <dilename>\t - to display entire file.");					//done
			printf("\n ls \t\t\t - lists the current directory files.");					//done
			printf("\n rm <filename>\t - to delete file.");						//done
			printf("\n cp <srcfile> <destfile>\t - copy contents of src file to dest file.");
			printf("\n mkdir <directory name>\t - to create directory.");				//done
			printf("\n rmdir <directory name> \t - to remove directory.");
			printf("\n cd <directory name>\t - to change directory.");				//done
			printf("\n rename <oldname> <newname> \t - to write file.");
			printf("\n exit/q \t - to exit from shell.");							//done
			printf("\n help/h \t - for help.");								//done
		}
		
                
		 else if((strcmp(cmd,"create"))==0)
 		{
   	 		c_r_val=my_create(tok[1]);
			if(c_r_val==-1)
				printf("\nInvalid filename...!!!\n");
			else
			{
				printf("%d\n",c_r_val);
				sblk.filecnt++;
				mk_entry(tok[1],c_r_val);
 			}
		}
		 else if((strcmp(cmd,"mkdir"))==0)
 		{
   	 		c_r_val=my_mkdir(tok[1]);
			if(c_r_val==-1)
				printf("\nInvalid directoryname...!!!\n");
			else
			{
				printf("%d\n",c_r_val);
				sblk.filecnt++;
				sblk.dircnt++;
				mk_entry(tok[1],c_r_val);
			}
 		}
                else if((strcmp(cmd,"cd"))==0)
 		{
   	 		//printf("\nMYSHELL/%s::",tok[1]);
			change_directory(tok[1],cdflag);
                }
		else if((strcmp(cmd,"cd .."))==0)
		{
			//goto myshell;
		}
		else if((strcmp(cmd,"cat"))==0)
 		{
   	 		my_open(tok[1],'r');
 		}
		else if((strcmp(cmd,"write"))==0)
 		{
			printf("If U Want To Quite Then Press #..........\n");
	 		my_open(tok[1],'w');
 		}

		else if((strcmp(cmd,"fstat"))==0)
 		{
			for(k3=0; k3<sblk.dircnt; k3++)
			{
			for(k1=0; k1<=11; k1++)
        		{
        			if(strcmp(d1[k3][k1].fname,tok[1])==0)
				{
					display_inode(tok[1],k1+1);
					break;
				}
	
			}
			}
				//display_inode(tok[1],k1);	 
        	}
		else if(strcmp(cmd,"ls")==0)
		{
			disp_dir_content();
		}
                else if(strcmp(cmd,"rm")==0)
		{
			myval=remove_file(tok[1]);
			if(myval==0)
			{
				printf("\nFile removed successfully...!!!\n");
				--sblk.filecnt;
			}
			else if(myval==-1)
				printf("\nFile does not exit...!!!\n");
		}
		
		else if(strcmp(cmd,"mount")==0)
		{
			my_mount(fs);
		}
		else
		{
			printf("\nCommand not found: for help type \"h\" or \"help\" \n");
		}
	}

	printf("\n");
	return 0;
}

