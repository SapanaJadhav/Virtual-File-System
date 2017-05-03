#include<stdlib.h>
#include"fs.h"
#include<stdio.h>

//void mk_initialize();

SB sblk;
inode in1;
Incore_i incore1;

void mk_initialize()
{
	int j,n3,n2=No_Of_Free_Inode;
        int rem_inode=8;
	sblk.size_file_system=1046576;		//1MB=1046576 bytes
	sblk.file_system_number=1;

	sblk.no_of_total_inode=500;
	sblk.no_of_free_inode = sblk.no_of_total_inode - sblk.no_allocated_inodes;
	sblk.size_of_inode_block = sizeof(struct INDEXNODE);

	sblk.size_of_block = 1024;				//1KB = 1024bytes
	sblk.no_of_free_blocks = sblk.total_no_of_block - sblk.no_allocated_blocks;

	
	//sblk.mount_flag;
 	fp1=fopen("input1.txt","w");
	fp2=fopen("input2.txt","w");        
	for(i=1; i<=10; i++)			//No_of_Free_Data_Blocks
	{
		sblk.free_data_block_list[i]=0;
		//printf("%ld	",sblk.free_data_block_list[i]);
	}
printf("\n");
	n3=sblk.no_of_total_inode;
	//Inode content
	
	in1.i_ino=0;
	in1.file_type='b';
	in1.atime=0;
	in1.mtime=0;
	in1.link_count=0;
	in1.perm=000;
	in1.file_size=0;
	in1.no_data_blocks=0;

      
			for(j=1; j<=8; j++) 			//No_Of_Free_Inode
			{
             	             	sblk.free_inode_list[j]=j;
				printf("%ld	",sblk.free_inode_list[j]);
			}

	
	return;
}
