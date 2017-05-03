#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"fs.h"

SB sblk;
DEntry d1[21][11];
inode in1;
int i2,fd,i=1,k=0,k1;
char *ptr;
int my_create(char *filename)
{
	char *token1;
	
        ptr=strstr(filename,".");
        if(ptr==NULL)
        {
	  //printf("Invalid File Name");
         return -1;
         }

	fs=fopen("myfs.txt","w+");
	fseek(fs,sizeof(struct SUPERBLOCK),SEEK_SET);

	fd=my_ialloc(sblk.file_system_number);
		//printf("............%d",fd);
   
	d1[k1][k].inode_num=fd;
	strcpy(d1[k1][k].fname,filename);
       		
	//printf("%d\t\t\t\t%s",d1[k].inode_num,d1[k].fname);					
	in1.i_ino=fd;
       	in1.file_type='r';							
	//in1.atime=0;
	//in1.mtime=0;
	in1.link_count;
	in1.perm=000; //remaining
	in1.file_size=0;
	in1.no_data_blocks=0;
	
	arr[fd].i_ino=in1.i_ino;
	arr[fd].file_type=in1.file_type;
	//printf("\nCreation  Time=%ld	\nModified Time=%ld",time(&in1.atime),time(&in1.mtime));
	//arr[fd].atime=in1.atime;
        //arr[filecnt].mtime=in1.addr;	
	//arr[fd].mtime=in1.mtime;	
	arr[fd].link_count=in1.link_count;
	arr[fd].perm=0777;
	arr[fd].mode1=in1.mode1;
	arr[fd].file_size=in1.file_size;
	arr[fd].no_data_blocks=in1.no_data_blocks;
      	k++;
	
	fclose(fs);
	return fd;
}

