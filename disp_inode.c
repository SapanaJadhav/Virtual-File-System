#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

#include"fs.h"

int k1;
SB sblk;
inode in1;
DEntry d1[21][11];
void display_inode(char *fname,int k1)
{
	
	printf("\nFilename\t\t=%s",fname);

	mk_entry(fname,k1);
	/*for(k1=; k1<6; k1++)
        {
        	if(d1[k1].fname==fname)
			break;
	}*/
	printf("\ninode_number\t\t=%d",arr[k1].i_ino);
	printf("\nFile Type\t\t=%c",arr[k1].file_type);
	//printf("\nCreation  Time=%ld	\nModified Time=%ld",time(&in1.atime),time(&in1.mtime));
	//printf("\ncreation time \t\t=%ld\nmodified time\t\t=%ld",time(&in1.atime),time(&in1.mtime));	
	printf("\nLink_count\t\t=%d",arr[k1].link_count);
	printf("\npermission\t\t=0777");
	printf("\nfile mode\t\t=%c",arr[k1].mode1);
	printf("\nFile_size\t\t=%d bytes",arr[k1].file_size);
	printf("\nNo_of_data Blocks	= %ld\n",arr[k1].no_data_blocks);

	
	/*printf("\ninode_number\t\t=%d",in1.i_ino);
	printf("\nFile Type\t\t=%c",in1.file_type);
	//printf("\nCreation  Time=%ld	\nModified Time=%ld",time(&in1.atime),time(&in1.mtime));
	printf("\ncreation time \t\t=%ld\nmodified time\t\t=%ld",time(&in1.atime),time(&in1.mtime));	
	printf("\nLink_count\t\t=%d",in1.link_count);
	printf("\npermission\t\t=0777");
	printf("\nfile mode\t\t=%c",in1.mode1);
	printf("\nFile_size\t\t=%d bytes",in1.file_size);
	printf("\nNo_of_data Blocks	= %ld\n",in1.no_data_blocks);
	*/
	return ;
}
