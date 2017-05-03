#include<stdlib.h>
#include"fs.h"
#include<stdio.h>

//void mk_initialize();

SB sblk;
inode in1;
Incore_i incore1;
DEntry d1[21][11];								//21 directory count
//inode_table i_table;
void mk_initialize()
{
       	fs=fopen("myfs.txt","a");
	if(fs==NULL)
		printf("\nFile opening error...!!!\n");
	else
	{
	fseek(fs,0,SEEK_SET);

	sblk.filecnt=0;    
	sblk.dircnt=1;
	rem_inode=1;
	
	int i,j,n1,n3,n2,nn;
        n1=No_Of_Free_Inode;

    	nn=max_file_size;
   	char m1,buff[nn];

      	//No_Of_Inode =500;
        //No_Of_Free_Block=1000;
	sblk.size_file_system=1046576;
	
        n2=No_Of_Inode;
        n3=No_Of_Free_Block;
	
	//1MB=1046576 bytes
	sblk.file_system_number=1;
	sblk.no_of_total_inode=500;
	sblk.no_of_free_inode = sblk.no_of_total_inode - sblk.no_allocated_inodes;
	sblk.size_of_inode_block = sizeof(struct INDEXNODE);
	sblk.size_of_block = 1024;				//1KB = 1024bytes
	sblk.no_of_free_blocks = sblk.total_no_of_block - sblk.no_allocated_blocks;
         
	for(i=1; i<=n3-1; i++)	
	{										//No_of_Free_Data_Blocks
		sblk.free_data_block_list[i]=0;
         }
	for(j=1; j<=n1; j++)
	{
                sblk.free_inode_list[j]=j;
	}
											
	in1.i_ino=0;
	in1.file_type=' ';
	in1.atime=0;
	in1.mtime=0;
	in1.link_count=0;
	in1.perm=777;
	in1.file_size=0;
	in1.no_data_blocks=0;

	for(i=1; i<5; i++)
	{
		arr[i].i_ino=0;
		arr[i].file_type=' ';
		//arr[i].atime=0;
		//arr[i].mtime=0;
		arr[i].link_count=0;
		arr[i].perm=777;
		arr[i].file_size=0;
		arr[i].no_data_blocks=0;
		//fwrite(&arr[i],sizeof(struct INDEXNODE),1,fs);		
	}

	}
	fclose(fs);
}
