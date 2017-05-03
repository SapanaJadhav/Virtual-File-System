#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"fs.h"

SB sblk;
DEntry d1[21][6];
inode in1;

inode in1;
int fd,k1,i1=0;//,k=0;
int my_mkdir(char *filename)
{
	char dirname[14],*token;

	strcpy(dirname,filename);

	token=strtok(dirname,".");
	if(strcmp(token,filename)!=0)
		return -1;
	
	sblk.dircnt=1;
	k1=sblk.dircnt;
	fd=my_ialloc(sblk.file_system_number);
		//printf("............%d",fd);
   
	d1[k1][k].inode_num=fd;
	strcpy(d1[k1][k].fname,filename);
       							//printf(".dddd    %d",d1[i].inode_num);
	

	in1.i_ino=fd;
       	in1.file_type='d';							//printf("iiiiiiiiiiii%d",in1.i_ino)	in1.file_type='R';
	//in1.atime=0;
	//in1.mtime=0;
	in1.link_count;
	in1.perm=000; //remaining
	in1.file_size=0;
	in1.no_data_blocks=0;


	arr[fd].i_ino=in1.i_ino;
	arr[fd].file_type=in1.file_type;
	
	arr[fd].link_count=in1.link_count;
	arr[fd].perm=0777;
	arr[fd].mode1=in1.mode1;
	arr[fd].file_size=in1.file_size;
	arr[fd].no_data_blocks=in1.no_data_blocks;
      	

	k++;

	return fd;
}

