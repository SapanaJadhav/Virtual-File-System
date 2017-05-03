#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

#define ck(x) \
if( (x) == (-1) ){ perror("");exit(EXIT_FAILURE);}

/* read a buffer from a file */
ssize_t readall(int fd, void *buf, size_t *bytes)
{
     ssize_t nread = 0, n=0;
     size_t nbyte = *bytes;

     do {
         if ((n = read(fd, &((char *)buf)[nread], nbyte - nread)) == -1) {
             if (errno == EINTR)
                 continue;
             else
                 return (-1);
         }
         if (n == 0)
             return nread;
         nread += n;
     } while (nread < nbyte);
     return nread;
}

/* read control */
void readfile(char *fname, char *buffer, size_t *size, mode_t *mode)
{
   int fd=0;   
   struct stat st;
   
   ck(fd=open(fname,O_RDONLY) );
   ck(fstat(fd,&st) );
   *size=st.st_size;   
   *mode=st.st_mode;
   buffer=calloc(1,*size+1);
   ck(readall(fd, buffer, size) );    
   ck(close(fd) );
}


int main(int argc, char *argv[])
{
   char *buffer=NULL;
   size_t size;
   mode_t mode;
 
   readfile(argv[1],buffer,&size,&mode);
   /* play with buffer here  */
	printf("%s",buffer);

   free(buffer);
   return 0;  
}
