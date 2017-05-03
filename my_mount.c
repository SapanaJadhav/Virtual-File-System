#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"fs.h"
SB sblk;
DEntry d1[11],d2[11];
inode in1,arr1[50];
int offset,j,offset1;
FILE *fs1;
char ch2;

void my_mount(FILE *fs)
{
	int i_offset,d_offset;
	fs=fopen("myfs.txt","r");
	fseek(fs,0,SEEK_SET);

	fread(&sblk,(sizeof(struct SUPERBLOCK)),1,fs);
	//printf("\n filecnt = %d\n",sblk.filecnt);

	for(i=0; i<sblk.filecnt; i++)
	{      
		i_offset =  (sizeof(struct SUPERBLOCK)) + (sizeof(struct INDEXNODE)*i);
		fseek(fs,i_offset,SEEK_SET);
		fread(&arr1[i],sizeof(struct INDEXNODE),1,fs);
	
		//printf("\ninode_number\t\t=%d",arr1[i].i_ino);
		//printf("\nFile Type\t\t=%c",arr1[i].file_type);
		//printf("\nCreation  Time=%ld	\nModified Time=%ld",time(&in1.atime),time(&in1.mtime));
		//printf("\ncreation time \t\t=%ld\nmodified time\t\t=%ld",time(&in1.atime),time(&in1.mtime));	
		//printf("\nLink_count\t\t=%d",arr1[i].link_count);
		//printf("\npermission\t\t=0777");
		//printf("\nfile mode\t\t=%c",arr1[i].mode1);
		//printf("\nFile_size\t\t=%d bytes",arr1[i].file_size);
		//printf("\nNo_of_data Blocks	= %ld\n",arr1[i].no_data_blocks);

	}

	for(i=0,j=0; i<sblk.filecnt; i++,j++)
	{
		d_offset =  (sizeof(struct SUPERBLOCK)) + (sizeof(struct INDEXNODE)*(sblk.filecnt)) + (sizeof(struct Dir_Entry)*j); 
		fseek(fs,d_offset,SEEK_SET);
		fread(&d2[i],sizeof(struct Dir_Entry),1,fs);

		//printf("\n%d\t\t\t\t%s",d2[i].inode_num,d2[i].fname);
	}
	
	fs1=fopen("demo1.txt","r");
	fseek(fs1,0,SEEK_SET);
	
	ch2=fgetc(fp1);
	while(ch2!=EOF)
	{
		fprintf(fs,"%c",ch2);
		ch2=fgetc(fp1);
	}
	
}
