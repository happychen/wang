#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char buf[5];
    int fd;

    fd = open("1.txt", O_RDWR);
    if (fd < 0) 
    {
        perror("open 1.txt");
        exit(1);
    }

    lseek(fd, 2, SEEK_SET);
    write(fd, "H", 1);
    close(fd);
    return 0;
}
