#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd, n;
    char buf[4096];

    fd = open("/hello", O_RDWR);
    if (fd < 0) 
    {
        perror("open error:");
        exit(1);
    }
    n = read (fd, buf, 4096);
    if (n < 0) 
    {
        perror("read error:");
        exit(1);
    }
    printf("read data is :%s\n", buf);
    close(fd);
    return 0;
}
