#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"fs.h"
SB sblk;
DEntry d1[21][11],d2[21][11];
inode in1;
int offset,j,offset1,k1;
void mk_entry(char fname[],int c_r_val)
{
         k1==sblk.dircnt;
	fs=fopen("myfs.txt","w+");
        d1[k1][c_r_val].inode_num=c_r_val;
	strcpy(d1[k1][c_r_val].fname,fname);
 
	//filecnt=c_r_val;
	arr[c_r_val].i_ino=c_r_val;
	arr[c_r_val].file_type=in1.file_type;
	//printf("\nCreation  Time=%ld	\nModified Time=%ld",time(&in1.atime),time(&in1.mtime));
	//arr[filecnt].atime=in1.atime;
        //arr[filecnt].mtime=in1.addr;	
	//arr[filecnt].mtime=in1.mtime;
	arr[c_r_val].link_count=in1.link_count;
	arr[c_r_val].perm=0777;
	arr[c_r_val].mode1=in1.mode1;
	arr[c_r_val].file_size=in1.file_size;
	arr[c_r_val].no_data_blocks=in1.no_data_blocks;

	fseek(fs,0,SEEK_SET);
	fwrite(&sblk,sizeof(struct SUPERBLOCK),1,fs);

	for(i=0; i<sblk.filecnt; i++)
	{      
	offset1 =  (sizeof(struct SUPERBLOCK)) + (sizeof(struct INDEXNODE)*i);
	fseek(fs,offset1,SEEK_SET);
	fwrite(&arr[i+1],sizeof(struct INDEXNODE),1,fs);
	//fseek(fs,offset1,SEEK_SET);
	//fread(&in1,sizeof(struct INDEXNODE),1,fs);

	}

	for(i=0,j=0; i<sblk.filecnt; i++,j++)
	{
		offset =  (sizeof(struct SUPERBLOCK)) + (sizeof(struct INDEXNODE)*(sblk.filecnt)) + (sizeof(struct Dir_Entry)*j); 
		fseek(fs,offset,SEEK_SET);
		fwrite(&d1[k1][i],sizeof(struct Dir_Entry),1,fs);

		//printf("\n d1[%d] =  %d\t\t\t\t%s",i,d1[i].inode_num,d1[i].fname);
	        //fseek(fs, (sizeof(struct INDEXNODE) * c_r_val),SEEK_SET);
	        //fread(&d2,sizeof(struct Dir_Entry),1,fs);
	        //printf("\n d2 =  %d\t\t\t\t%s",d2.inode_num,d2.fname);
	}
	fclose(fs);	
}
	

