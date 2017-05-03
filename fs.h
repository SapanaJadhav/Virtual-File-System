#include<stdlib.h>
#include<string.h>
#include<sys/times.h>
#include<unistd.h>
#include<stdio.h>
#define No_Of_Inode  500
#define Size_of_block 1024 
#define File_name_size 14
#define No_of_incore_inode 15
//#define no_of_blocks 1024
#define No_Of_Free_Inode 8
#define No_Of_Free_Block 1000
#define max_file_size 5120
//int No_Of_Free_Block=1000;

char data_block[1024];
FILE *fp1,*fs;

typedef struct SUPERBLOCK
{
	unsigned long size_file_system;
	int file_system_number;
	
	int no_of_total_inode;
	int no_of_free_inode;
	int size_of_inode_block;
        int  no_allocated_blocks;
	int no_allocated_inodes;
	int size_of_block;
	int filecnt;
	int dircnt;
	int no_of_free_blocks;
	
	int total_no_of_block;
	
	unsigned int mount_flag;
	unsigned long  free_inode_list[No_Of_Free_Inode];
	unsigned long  free_data_block_list[No_Of_Free_Block];			
}SB;

typedef struct INDEXNODE
{
	int block;					
	int i_ino;
	char file_type;
	time_t   atime;
	time_t  mtime;
	int link_count;
	int perm;
        char mode1;
	int file_size;
	unsigned long no_data_blocks;
	int allocated_data_block[10];
}inode;


typedef struct incore_inode
{
	inode i1;
	char mode;
	int inode; 			
}Incore_i;


/*struct  inode_table
{
	   inode node;
}arr[No_Of_Inode];			
*/

inode arr[No_Of_Inode];
typedef struct Dir_Entry
{
	int inode_num;
	char fname[14];
}DEntry;

typedef struct data_block
{
	char db[1024][1024];
}data_blk;

int i,k;
int rem_inode,nn;
int c_r_val;
char *buff;





