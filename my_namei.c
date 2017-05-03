#include<stdio.h>
#include<string.h>
#include"fs.h"
SB sblk;
DEntry d1[6];
inode in1;
int my_namei(char *filename)
{

int i,n1;
n1=No_Of_Inode;
for(i=1;i<=10;i++)
{
	if(strcmp(d1[i].fname,filename)==0)
	{
		return d1[i].inode_num;
	}
}
//if(i==11)
 //      {
          return -1;
//	}

}
