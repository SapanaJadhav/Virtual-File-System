#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"fs.h"
SB sblk;
DEntry d1;
inode in1;
int cnt=0,k,st,j;
char ch1;
void my_write(int fd,char data_block[],int bytes)
{
	int i=0,nnnn;
	fp1=fopen("demo1.txt","a");
	fs=fopen("myfs.txt","a");
	nnnn=((sizeof(struct SUPERBLOCK))+((sizeof(struct INDEXNODE))*500));
	printf("\n%d",nnnn);
	fseek(fs,((sizeof(struct SUPERBLOCK))+((sizeof(struct INDEXNODE))*500)),SEEK_SET);

	fprintf(fp1,"%d",fd);
	fprintf(fs,"%d",fd);
	printf("\nEnter data:\n");

	ch1=getchar();
	fprintf(fp1,"%c",ch1);
	fprintf(fs,"%c",ch1);
	/*gets(data_block);

	printf("\nEntered character is :%s",data_block);

	fprintf(fp1,"%s",data_block);*/

	while(ch1!='#') 
	{
		//printf("\nin while loop...!!!");
		i++;
                  ch1=getchar();
		fprintf(fp1,"%c",ch1);
		fprintf(fs,"%c",ch1);
        }
	
	fclose(fp1);
	fclose(fs);
	printf("\n%d",i);
	in1.file_size=i;
	arr[fd].file_size=i;
	
	//fseek(fs,sizeof(struct SUPERBLOCK),SEEK_SET);
	   
	if(i==nn)
        	printf("File Size Exceeds");
 
	if(i<1024)
       {
             	// printf("data block..%d",st);
		st--;
		j++;
		sblk.free_data_block_list[cnt]=1;
		cnt++;
		in1.no_data_blocks=cnt;
	//	arr[k].node.no_data_blocks=cnt;
       }
       j=i/1024;
      
	st=st-(j+1);
	for(cnt=0; cnt<st; cnt++)
		sblk.free_data_block_list[cnt]=1;
 	
	sblk.no_of_free_blocks=st;

 //      	printf("data block..%d",st);
       		//}
			//printf("\n%s",buff);
}
