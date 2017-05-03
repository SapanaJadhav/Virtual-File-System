myexe:one first second third third1 fourth0 fourth1 fifth sixth seventh eighth ningth ten eleven twelve
	gcc shell.c mk_initialize.o my_iget.o my_ialloc.o my_create.o mk_entry.o my_namei.o my_open.o my_write.o my_read.o  disp_dir_content.o disp_inode.o remov_file.o my_mkdir.o my_mount.o change_directory.o -o myexe
one:
	gcc -c mk_initialize.c
first:
	gcc -c my_iget.c
second:
	gcc -c my_ialloc.c
third:
	gcc -c my_create.c
third1:
	gcc -c mk_entry.c
fourth0:
	gcc -c my_namei.c
fourth1:
	gcc -c my_open.c
fifth:
	gcc -c my_write.c
sixth:
	gcc -c my_read.c
seventh:
	gcc -c disp_dir_content.c
eighth:
	gcc -c disp_inode.c
ningth:
	gcc -c remov_file.c
ten : 
	gcc -c my_mkdir.c 
eleven:
	gcc -c my_mount.c
twelve:
	gcc -c change_directory.c
