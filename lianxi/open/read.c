#include <stdio.h>

int main(int argc, const char *argv[])
{
    int fd_in;
    int fd_out;
    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);

    char buf[10];
    int n;
    while(n = read(fd_in, buf, 10) > 0)
        write(fd_out, buf, n);

    close(fd_in);
    close(fd_out);
    return 0;
}
