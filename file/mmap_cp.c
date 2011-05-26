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
    int fd1, fd2;
    struct stat *s;
    if (argc < 3) 
    {
        perror("open error");
        exit(1);
    }
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) 
    {
        perror("open argv[1]");
        exit(1);
    }

   
    ps = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
    if (ps == MAP_FAILED) 
    {
        perror("mmap ps");
        exit(1);
    }

    lseek(fd2, s.st_size-1, SEEK_SET);   
    write(fd2, "", 1);

    pd = mmap(NULL, s.st_size, PROT_WRITE, MAP_SHARED, fd2, 0);
    if (pd == MAP_FAILED) 
    {
        perror("mmap pd ");
        exit(1);
    }

    memcpy(ps, pd, s.st_size);
    close(fd1);
    close(fd2);

    munmap(ps, s.st_size);
    return 0;
}
