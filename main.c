#include<stdio.h>
#include"fs.h"
#include<stdlib.h>
//#include"mk_initialize.c"
void mk_initialize();
int my_ialloc(int no1);
int my_iget(int no);
int my_create(char *filename);
int my_namei(char *filename);
int my_open(char *fname);
void disp_dir_content();
void my_write(int fd,char *buff,int bytes);
SB sblk;
//DEntry d1;
int main()
{
         int n,fd,i=1;	
	mk_initialize();	
        
	my_create(".");
	
        printf("Second File Is \n");
        my_create("..");
	
        my_create("abc.txt");
        //fd=my_namei("sap.txt");
        //printf("\nFd after namei  descriptor is %d",fd);
        my_open("sap.txt");
       // printf("\ninod e=%d",d1[i].inode_num);
        //printf("\n%s\t",d1[i].fname);
         disp_dir_content();     
        //printf("file name =%s\t inode number=%d\tFile descriptor is=%d",d1[i++]fname,d1[i++].inode_num,fd);
	return;
}
