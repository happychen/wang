#include <stdio.h>
#include <stdlib.h>
#include <sys/mmap.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, const char *argv[])
{
    char *ps, *pd;
    int in, out;
    struct stat *statbuf;
    if (argc < 2) 
    {
        perror("open error");
        exit(1);
    }
    in = open(argv[1], O_RDONLY);
    if (in < 0) 
    {
        perror("open argv[1]");
        exit(1);
    }


    if (stat(argv[1], &statbuf) == -1) 
    {
        perror("fail to stat");
        exit(1);
    }
    printf("size : %d\n", (int)statbuf.st_size);
    ps = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, in, 0);
    
    if (ps == MAP_FAILED) 
    {
        perror("mmap ps");
        exit(1);
    }
    close(in);
    out = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
    if (out < 0) 
    {
        perror("open desfile error");
        exit(1);
    }

#if 1 
    lseek(out, statbuf.st_size-1, SEEK_SET);
    write(out ,"", 1);
#endif

    pd = momap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, out, 0);
    if (pd == MAP_FAILED) 
    {
        perror("mmap pd");
        exit(1);
    }
    close(out);
    memcpy(pd, ps, statbuf.st_size);
    munmap(ps, statbuf.st_size);
    munmap(pd, statbuf.st_size);

    return 0;
}
