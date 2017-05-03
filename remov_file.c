#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"fs.h"
SB sblk;
DEntry d1[11];
inode in1;
int kk;
int remove_file(char *filename)
{
	fs=fopen("myfs.txt","w+");
	printf("\nIn remove function..");
	int i,n1;
	
	//kk=my_namei(filename);
	for(i=1;i<=sblk.filecnt;i++)
	{
		if(strcmp(d1[i].fname,filename)==0)
		{
			kk=d1[i].inode_num;
			printf("\n%d",kk);
			break;
		}
	}

	fseek(fs,((sizeof(struct SUPERBLOCK))+(sizeof(struct INDEXNODE) * (kk-1))),SEEK_SET);
	if(kk<=10)
	{
	printf("\n%d",kk);
	arr[kk].i_ino=0;
	arr[kk].file_type=' ';
	arr[kk].atime=0;
	arr[kk].mtime=0;
	arr[kk].link_count=0;
	arr[kk].perm=0;
	arr[kk].file_size=0;
	arr[kk].no_data_blocks=0;
	
	fwrite(&arr[kk],sizeof(struct INDEXNODE),1,fs);
	//strcpy(d1[kk].fname,NULL);
	d1[kk].inode_num=0;
	printf("%d",d1[kk].inode_num);
	c_r_val--;
	return 0;
	}

	else 
	{
		return -1;
	}
}
