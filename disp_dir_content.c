#include<stdio.h>
#include<stdlib.h>
#include"fs.h"

SB sblk;
DEntry d1[21][11];
inode in1;
void disp_dir_content()
{
	int i,n,k1,j;
	k1=sblk.filecnt;
	printf("Directory Content Are\n");
        printf("Inode\t\t\t\tFile_name\n");

	//printf("\ndir cnt = %d",sblk.dircnt);
	//printf("\nfile cnt = %d",sblk.filecnt);
	for(j=0; j<=sblk.dircnt; j++)
	{
		for(i=0; i<=sblk.filecnt-1; i++)
        	{
			if(d1[j][i].inode_num !=0)
			{
				printf("%d\t\t\t\t%s",d1[j][i].inode_num,d1[j][i].fname);
         				printf("\n");
			}
			else if(d1[j][i].inode_num==0)
				continue;
		}
	}
         
}
