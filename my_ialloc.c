#include<stdio.h>
#include"fs.h"
SB sblk;

int my_ialloc(int fs_number)
{
  
	int n,n1,i,j=0;
	n=No_Of_Free_Inode;
	n1=No_Of_Inode;
      	int inode;
	if(sblk.file_system_number==1)
	{       

                if(rem_inode==n)								   // if free list is empty
                    {          j=0;
				for(i=rem_inode+1;i<(rem_inode+n);i++)
                        {
                        		sblk.free_inode_list[j]=i;
					//printf("%ld    ",sblk.free_inode_list[j]);
					j++;
                      		}
                              printf("\n");
			      //for(i=0;i<8;i++)
                               //printf("%ld   ",sblk.free_inode_list[i]);
                              
                                  rem_inode= sblk.free_inode_list[0];
                                  printf("changed inode is%d",rem_inode);
                               inode=my_iget(rem_inode); //else call to get_inode()
                               rem_inode++; 
                                                	  //n--;
                	       //printf("%d\t%d\n",inode,rem_inode);
                                 return;
                    }
                  
                  if(rem_inode==n1)   //if all DILB inode allocated
                    {

		     return -1;
		     }
                 	inode=my_iget(rem_inode); //else call to get_inode()
                       rem_inode++;                	  //n--;
                       //printf("\ninode=%d",inode);
		return inode;
	}
}
