#include<stdio.h>
#include<stdlib.h>
#include"fs.h"


SB sblk;
inode in1;

int my_iget(int no)
{
	int n,i,j=0,n1,flg=0;
	n=No_Of_Free_Inode;
	n1=No_Of_Inode;
	
	for(i=1; i<n; i++)
	{
			in1.link_count=0;							//printf("%ld",sblk.free_inode_list[i]);
		if(sblk.free_inode_list[i] == no)
		{
			flg=1;
			in1.link_count=1;
			break;
		}
	}
	if(flg==1)
	{
		return i;
		
	}
	if(i==sizeof(n))
		return -1;
       
}


